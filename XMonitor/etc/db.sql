BEGIN TRANSACTION;
CREATE TABLE server (id TEXT PRIMARY KEY, ip TEXT, name TEXT, desc TEXT, usr TEXT, pwd TEXT, active NUMERIC, ui_scene_pos TEXT, status NUMERIC, step_status TEXT);
INSERT INTO "server" VALUES('1ecc4cfb810146eaa6cc78ec5c157994','172.28.13.18','ADC Server','This is ADC Server','euap','euap','false','-60,64','true','{ "check_cpu" : { "abc" : "abc", "status" : true }, "check_disk" : { "abc" : "abc", "status" : true }, "check_process" : { "abc" : "abc", "msg" : "TEST_PROCESS not started,", "status" : false }, "set_server_status" : { "server_failure" : true } }');
INSERT INTO "server" VALUES('615ffb16551d42b39b8672253428630e','172.28.13.16','MAS Server','This is MAS Server','mas','mas','false','154,79','false','');
CREATE TABLE step (id TEXT PRIMARY KEY, svr_id TEXT, name TEXT, desc TEXT, cmd TEXT, script TEXT, cmd_result TEXT, seq NUMERIC);
INSERT INTO "step" VALUES('c39a611eb2be460c844fb5a20569e1a5','1ecc4cfb810146eaa6cc78ec5c157994','check_disk','检查磁盘空间情况','df -h','//步骤上下文：用于获取别的步骤的运行结果
eval(xCtx);
//步骤输入：命令运行的结果作为步骤脚本的输入
var input = xIn;	
//将输入切分成行
var lines = input.split(''\n'');
//用这种方式打log。点击“Run Command”按钮，log信息将被输入到右上方的窗口中
//xLog.appendPlainText( lines.length );

//这个对象将被作为脚本结果返回给工具。让我们严谨点，默认认为这个检查步骤会失败（status为false）除status和后面将介绍的少数几个属性外，其他属性可以自定义。
var rtn = {status:false, abc:"abc"};


//这个例子中，我们关心/home挂接的下的硬盘使用情况。以空白字符（空格，制表符等）为分界，切分指定一样字符串。
var words = lines[3].split(/\s+/);
//表示硬盘使用量的单词在地4行第5个单词上（以零为下标起点）
var used = words[4]
//这时used这个字符串后面是有百分号（%）的，javascript的parseInt函数努力把一个字符串尝试转换成整数，这意味着parseInt会丢弃掉后面的%，这正好是我们想要的。
var usedPer = parseInt(used);

if(usedPer > 80){
    //超过80%了，也即剩余空间<20%。检查不通过。
    rtn.status = false;
    //对于这个不通过，给个原因吧。
    rtn[''msg''] = ''Disk space less than 20%'';
    
} else {
    //OK，磁盘够用。
    rtn.status = true;
}

//加上这句话，将本步检测的结果返回给工具。
JSON.stringify(rtn);','文件系统              容量  已用 可用 已用% 挂载点
/dev/sda1             9.9G  1.7G  7.8G  18% /
udev                  2.0G  136K  2.0G   1% /dev
/dev/sda7             198G   66G  123G  35% /home
/dev/sda2             9.9G  2.6G  6.9G  28% /usr
/dev/sda5              50G  279M   47G   1% /var
',1);
INSERT INTO "step" VALUES('a86b3ea3b5194a1385879f2c91f4b816','1ecc4cfb810146eaa6cc78ec5c157994','check_cpu','检查CPU使用情况','top -b -n1','eval(xCtx);
var input = xIn;
var lines = input.split(''\n'');

var rtn = {status:false, abc:"abc"};

//CPU相关数据所在行为第三行
var words = lines[2].split(/\s+/);
//后缀为id的，表示是空闲CPU的百分比。
var idle = words[4]

//转成数字，由于字符串里面还有其他非数字字符，可以把log打出来看看转的对不对。在这个例子中，你会发现尝试转换时不对的，所以我们要手动先处理下字符串。
//var idlePer = parseInt(idle);
//xLog.appendPlainText( idlePer );

//由于后面那个%id是不变的，所以我们从后面截掉3个字符。注意我是unused.length-4。为啥减的是4不是3捏？请参考javascript手册中对substring函数的表述。
idle = idle.substring(0, idle.length-4);
var idlePer = parseInt(idle);

if(idlePer < 50){
    //CPU空闲小于50%，也即CPU负载大于50%。好吧，这个例子中，我们认为负载过大，检查不通过。
    rtn.status = false;
    //对于这个不通过，给个原因吧。
    rtn[''msg''] = ''CPU overload...'';
    
} else {
    //OK，CPU很闲。
    rtn.status = true;
}

//加上这句话，将本步检测的结果返回给工具。
JSON.stringify(rtn);','top - 18:43:28 up 142 days,  3:05,  3 users,  load average: 0.06, 0.15, 0.07
Tasks: 189 total,   1 running, 188 sleeping,   0 stopped,   0 zombie
Cpu(s):  0.3%us,  0.0%sy,  0.0%ni, 99.7%id,  0.0%wa,  0.0%hi,  0.0%si,  0.0%st
Mem:   4036872k total,  3966900k used,    69972k free,   455144k buffers
Swap:  8393920k total,      136k used,  8393784k free,   719788k cached

  PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND            
 4216 root      15   0 42148 8488 3792 S    2  0.2  69:06.60 X                  
28524 euap      16   0 1814m 902m  20m S    2 22.9  58:27.89 java               
24162 euap      15   0  5588 1176  788 R    2  0.0   0:00.05 top                
    1 root      16   0   776  300  252 S    0  0.0   0:03.07 init               
    2 root      RT   0     0    0    0 S    0  0.0   0:00.22 migration/0        
    3 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/0        
    4 root      RT   0     0    0    0 S    0  0.0   0:00.54 migration/1        
    5 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/1        
    6 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/2        
    7 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/2        
    8 root      RT   0     0    0    0 S    0  0.0   0:00.06 migration/3        
    9 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/3        
   10 root      RT   0     0    0    0 S    0  0.0   0:00.06 migration/4        
   11 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/4        
   12 root      RT   0     0    0    0 S    0  0.0   0:00.06 migration/5        
   13 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/5        
   14 root      RT   0     0    0    0 S    0  0.0   0:00.01 migration/6        
   15 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/6        
   16 root      RT   0     0    0    0 S    0  0.0   0:00.04 migration/7        
   17 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/7        
   18 root      RT   0     0    0    0 S    0  0.0   0:00.18 migration/8        
   19 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/8        
   20 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/9        
   21 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/9        
   22 root      RT   0     0    0    0 S    0  0.0   0:00.21 migration/10       
   23 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/10       
   24 root      RT   0     0    0    0 S    0  0.0   0:00.02 migration/11       
   25 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/11       
   26 root      RT   0     0    0    0 S    0  0.0   0:01.08 migration/12       
   27 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/12       
   28 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/13       
   29 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/13       
   30 root      RT   0     0    0    0 S    0  0.0   0:01.64 migration/14       
   31 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/14       
   32 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/15       
   33 root      34  19     0    0    0 S    0  0.0   0:00.00 ksoftirqd/15       
   34 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/0           
   35 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/1           
   36 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/2           
   37 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/3           
   38 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/4           
   39 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/5           
   40 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/6           
   41 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/7           
   42 root      10  -5     0    0    0 S    0  0.0   0:00.01 events/8           
   43 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/9           
   44 root      10  -5     0    0    0 S    0  0.0   0:00.16 events/10          
   45 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/11          
   46 root      10  -5     0    0    0 S    0  0.0   0:00.17 events/12          
   47 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/13          
   48 root      10  -5     0    0    0 S    0  0.0   0:00.10 events/14          
   49 root      10  -5     0    0    0 S    0  0.0   0:00.00 events/15          
   50 root      17  -5     0    0    0 S    0  0.0   0:00.00 khelper            
   51 root      10  -5     0    0    0 S    0  0.0   0:00.00 kthread            
   70 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/0          
   71 root      10  -5     0    0    0 S    0  0.0   0:00.01 kblockd/1          
   72 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/2          
   73 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/3          
   74 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/4          
   75 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/5          
   76 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/6          
   77 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/7          
   78 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/8          
   79 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/9          
   80 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/10         
   81 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/11         
   82 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/12         
   83 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/13         
   84 root      10  -5     0    0    0 S    0  0.0   0:00.01 kblockd/14         
   85 root      10  -5     0    0    0 S    0  0.0   0:00.00 kblockd/15         
   86 root      10  -5     0    0    0 S    0  0.0   0:00.00 kacpid             
  352 root      15   0     0    0    0 S    0  0.0   0:00.00 pdflush            
  353 root      15   0     0    0    0 S    0  0.0   0:01.21 pdflush            
  354 root      15   0     0    0    0 S    0  0.0   0:00.45 kswapd1            
  355 root      15   0     0    0    0 S    0  0.0   0:00.27 kswapd0            
  356 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/0              
  357 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/1              
  358 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/2              
  359 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/3              
  360 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/4              
  361 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/5              
  362 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/6              
  363 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/7              
  364 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/8              
  365 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/9              
  366 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/10             
  367 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/11             
  368 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/12             
  369 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/13             
  370 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/14             
  371 root      11  -5     0    0    0 S    0  0.0   0:00.00 aio/15             
  584 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/0           
  585 root      11  -5     0    0    0 S    0  0.0   0:00.00 cqueue/1           
  586 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/2           
  587 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/3           
  588 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/4           
  589 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/5           
  590 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/6           
  591 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/7           
  592 root      11  -5     0    0    0 S    0  0.0   0:00.00 cqueue/8           
  593 root      11  -5     0    0    0 S    0  0.0   0:00.00 cqueue/9           
  594 root      11  -5     0    0    0 S    0  0.0   0:00.00 cqueue/10          
  595 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/11          
  596 root      11  -5     0    0    0 S    0  0.0   0:00.00 cqueue/12          
  597 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/13          
  598 root      11  -5     0    0    0 S    0  0.0   0:00.00 cqueue/14          
  599 root      10  -5     0    0    0 S    0  0.0   0:00.00 cqueue/15          
  600 root      10  -5     0    0    0 S    0  0.0   0:00.00 kseriod            
  631 root      10  -5     0    0    0 S    0  0.0   0:00.00 kpsmoused          
 1099 root      11  -5     0    0    0 S    0  0.0   0:00.00 scsi_eh_0          
 1162 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/0              
 1163 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/1              
 1164 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/2              
 1165 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/3              
 1166 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/4              
 1167 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/5              
 1168 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/6              
 1169 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/7              
 1170 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/8              
 1171 root      11  -5     0    0    0 S    0  0.0   0:00.00 ata/9              
 1172 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/10             
 1173 root      11  -5     0    0    0 S    0  0.0   0:00.00 ata/11             
 1174 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/12             
 1175 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/13             
 1176 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/14             
 1177 root      10  -5     0    0    0 S    0  0.0   0:00.00 ata/15             
 1360 root      15   0     0    0    0 S    0  0.0   0:11.31 kjournald          
 1420 root      13  -4  7096  704  336 S    0  0.0   0:00.19 udevd              
 2077 root      10  -5     0    0    0 S    0  0.0   0:00.00 khubd              
 2550 root      15   0     0    0    0 S    0  0.0   1:20.94 kjournald          
 2552 root      15   0     0    0    0 S    0  0.0   0:05.12 kjournald          
 2554 root      15   0     0    0    0 S    0  0.0   0:15.68 kjournald          
 2955 root      16   0  2636  392  284 S    0  0.0   0:00.35 irqbalance         
 2974 root      15   0  6204  484  372 S    0  0.0   0:00.00 resmgrd            
 2977 root      15   0  8292  856  544 S    0  0.0   0:00.15 syslog-ng          
 2981 messageb  16   0 13028 1008  712 S    0  0.0   0:16.16 dbus-daemon        
 2982 root      16   0  2620  500  404 S    0  0.0   0:00.00 acpid              
 2985 root      16   0  2880  668  332 S    0  0.0   0:00.00 klogd              
 3005 root      16   0 13224 3288 1484 S    0  0.1   0:02.26 hald               
 3438 root      13  -3 12000  628  476 S    0  0.0   0:00.06 auditd             
 3440 root      11  -5     0    0    0 S    0  0.0   0:00.00 kauditd            
 3442 nobody    16   0  4704  444  332 S    0  0.0   0:00.00 portmap            
 3633 root      15   0  120m 1084  780 S    0  0.0   0:04.03 nscd               
 3757 root      18   0  6012  684  584 S    0  0.0   0:00.00 hald-addon-acpi    
 3898 daemon    16   0 11068  836  516 S    0  0.0   0:02.91 slpd               
 4015 root      15   0 91656 9924 5488 S    0  0.2   0:35.40 owcimomd           
 4027 root      16   0 24892 1416  936 S    0  0.0   0:01.85 sshd               
 4108 root      17   0 53492  10m 2500 S    0  0.3   0:16.49 gdm                
 4118 root      18   0  2676  452  372 S    0  0.0   0:00.00 startpar           
 4121 lp        16   0 23180 4208 1376 S    0  0.1   0:00.17 cupsd              
 4192 root      16   0 20296 2056 1536 S    0  0.1   0:01.72 powersaved         
 4205 root      10  -5     0    0    0 S    0  0.0   1:53.83 ondemand           
 4215 root      17   0 59244 2932 2120 S    0  0.1   0:00.00 gdm                
 4229 ldap      18   0 69044 5040 2904 S    0  0.1   0:06.54 slapd              
 4329 root      17   0 21312 2160 1700 S    0  0.1   0:00.15 master             
 4348 root      16   0  5992  552  444 S    0  0.0   0:00.06 cron               
 4354 root      18   0  3056  708  612 S    0  0.0   0:00.01 mingetty           
 4355 root      18   0  3060  692  600 S    0  0.0   0:00.00 mingetty           
 4356 root      16   0  3060  696  600 S    0  0.0   0:00.00 mingetty           
 4357 root      16   0  3056  692  600 S    0  0.0   0:00.00 mingetty           
 4358 root      18   0  3056  692  600 S    0  0.0   0:00.00 mingetty           
 4359 root      18   0  3060  692  600 S    0  0.0   0:00.00 mingetty           
 4403 gdm       15   0  174m  19m  11m S    0  0.5   0:24.35 gdmgreeter         
12454 cos       17   0 1765m 908m  12m S    0 23.0  44:19.80 java               
29306 siagent   16   0 1792m 259m  16m S    0  6.6   1215:49 java               
 7194 root      16   0 37496 2640 2068 S    0  0.1   0:09.56 sshd               
 7199 cps       16   0 37496 1784 1192 S    0  0.0   0:30.83 sshd               
 7200 cps       15   0 10112 2396 1576 S    0  0.1   0:00.04 bash               
20279 euap      17   0 23620 1496 1108 S    0  0.0   0:00.14 su                 
20280 euap      15   0 10108 2456 1576 S    0  0.1   0:00.04 bash               
28895 cps       16   0 23616 1496 1108 S    0  0.0   0:00.14 su                 
28896 cps       16   0 10108 2392 1576 S    0  0.1   0:00.05 bash               
31453 root      16   0 37496 2640 2068 S    0  0.1   0:05.72 sshd               
31460 cps       16   0 37496 1784 1192 S    0  0.0   0:18.15 sshd               
31461 cps       16   0 10112 2400 1576 S    0  0.1   0:00.03 bash               
23416 root      16   0 37284 2600 2036 S    0  0.1   0:05.62 sshd               
23419 euap      16   0 37636 1848 1228 S    0  0.0   0:17.65 sshd               
23420 euap      16   0 22632 1724 1264 S    0  0.0   0:00.03 sftp-server        
12216 cps       16   0 1862m 552m  16m S    0 14.0   1660:36 java               
15746 postfix   16   0 21312 2112 1672 S    0  0.1   0:00.21 qmgr               
16956 root      16   0 37060 2812 1852 S    0  0.1   0:00.00 smbd               
16957 root      19   0 37060 1324  364 S    0  0.0   0:00.00 smbd               
 3891 root      18   0  2484  360  272 S    0  0.0   1:35.23 zmd                
19038 root      16   0 37496 2640 2068 S    0  0.1   0:00.00 sshd               
19045 euap      15   0 37628 1800 1196 S    0  0.0   0:00.10 sshd               
19048 euap      17   0 10108 2412 1548 S    0  0.1   0:00.04 bash               
23379 postfix   16   0 21276 2080 1656 S    0  0.1   0:00.00 pickup             
24156 root      15   0 37284 2592 2028 S    0  0.1   0:00.00 sshd               
24161 euap      15   0 37496 1652 1076 S    0  0.0   0:00.00 sshd               

',2);
INSERT INTO "step" VALUES('403723cf2f144e8f8978602261770823','1ecc4cfb810146eaa6cc78ec5c157994','check_process','检查进程','ps -ef|grep java','eval(xCtx);
var input = xIn;
var lines = input.split(''\n'');
//xLog.appendPlainText( lines.length );

var rtn = {status:false, abc:"abc"};
var stat = true;//下面，发现任何进程没启动则认为整个步骤检测不通过。
var errList = '''';

//本例将检查所有关注进程的运行情况。
var ps = ["cos","cps","siagent","euap","TEST_PROCESS"];
for(var i = 0; i<ps.length; i++){
	var processName = ps[i];
	var j;
	for(j = 0; j<lines.length; j++){
		var line = lines[j];
		//字符串开头找到指定进程字样，认为进程启动
		if( line.indexOf(processName) == 0 )
			break;
	}
	
	if(j>=lines.length){
		//找了一圈都没找到，说明这个进程没启动。发现任何期望的进程没启动则认为整个步骤检测不通过。
		stat = false;
		errList += processName+'' not started,'';
	}
}

if(!stat){
    //有进程没启动起来
    rtn.status = false;
    //对于这个不通过，给个原因吧。
    rtn[''msg''] = errList;
    
} else {
    //OK，所有进程都启起来了。
    rtn.status = true;
}

//加上这句话，将本步检测的结果返回给工具。
JSON.stringify(rtn);','cos      12454     1  0  2010 ?        00:44:19 /usr/local/jdk1.5.0_16/bin/java -Djava.util.logging.config.file=/home/cos/apache-tomcat-5.5.27/conf/logging.properties -Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m -Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager -Djava.endorsed.dirs=/home/cos/apache-tomcat-5.5.27/common/endorsed -classpath :/home/cos/apache-tomcat-5.5.27/bin/bootstrap.jar:/home/cos/apache-tomcat-5.5.27/bin/commons-logging-api.jar -Dcatalina.base=/home/cos/apache-tomcat-5.5.27 -Dcatalina.home=/home/cos/apache-tomcat-5.5.27 -Djava.io.tmpdir=/home/cos/apache-tomcat-5.5.27/temp org.apache.catalina.startup.Bootstrap start
siagent  29306     1  0  2010 ?        20:15:45 /usr/local/jdk1.5.0_16/bin/java -Djava.util.logging.config.file=/home/siagent/apache-tomcat-5.5.27/conf/logging.properties -Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m -Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager -Djava.endorsed.dirs=/home/siagent/apache-tomcat-5.5.27/common/endorsed -classpath :/home/siagent/apache-tomcat-5.5.27/bin/bootstrap.jar:/home/siagent/apache-tomcat-5.5.27/bin/commons-logging-api.jar -Dcatalina.base=/home/siagent/apache-tomcat-5.5.27 -Dcatalina.home=/home/siagent/apache-tomcat-5.5.27 -Djava.io.tmpdir=/home/siagent/apache-tomcat-5.5.27/temp org.apache.catalina.startup.Bootstrap start
euap     28524     1  0 Jan21 pts/0    00:58:26 /usr/local/jdk1.5.0_16/bin/java -Djava.util.logging.config.file=/home/euap/apache-tomcat-5.5.27/conf/logging.properties -Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m -Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager -Djava.endorsed.dirs=/home/euap/apache-tomcat-5.5.27/common/endorsed -classpath :/home/euap/apache-tomcat-5.5.27/bin/bootstrap.jar:/home/euap/apache-tomcat-5.5.27/bin/commons-logging-api.jar -Dcatalina.base=/home/euap/apache-tomcat-5.5.27 -Dcatalina.home=/home/euap/apache-tomcat-5.5.27 -Djava.io.tmpdir=/home/euap/apache-tomcat-5.5.27/temp org.apache.catalina.startup.Bootstrap start
cps      12216     1  4 Feb23 pts/0    1-03:39:20 /usr/local/jdk1.5.0_16/bin/java -Djava.util.logging.config.file=/home/cps/apache-tomcat-5.5.27/conf/logging.properties -Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m -Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager -Djava.endorsed.dirs=/home/cps/apache-tomcat-5.5.27/common/endorsed -classpath :/home/cps/apache-tomcat-5.5.27/bin/bootstrap.jar:/home/cps/apache-tomcat-5.5.27/bin/commons-logging-api.jar -Dcatalina.base=/home/cps/apache-tomcat-5.5.27 -Dcatalina.home=/home/cps/apache-tomcat-5.5.27 -Djava.io.tmpdir=/home/cps/apache-tomcat-5.5.27/temp org.apache.catalina.startup.Bootstrap start
euap     22932 22931  0 18:17 ?        00:00:00 bash -c ps -ef|grep java
euap     22957 22932  0 18:17 ?        00:00:00 grep java
',3);
INSERT INTO "step" VALUES('06bbdfbd3fc2474c9d0d6386e3b5d7b8','1ecc4cfb810146eaa6cc78ec5c157994','set_server_status','根据前面各步骤运行情况设定服务器状态','','eval(xCtx);

var step_check_disk_status = xCtx.check_disk.status;
var step_check_cpu_status = xCtx.check_cpu.status;
var step_check_process_status = xCtx.check_process.status;

var rtn = {server_failure: true}

//本例中设定只有在全部步骤都通过的情况下才认为服务器OK。当然，实际中，可能有些非关键的步骤失败不足以说明服务器不稳定，这个up to you：）
if(step_check_disk_status && step_check_cpu_status && step_check_process_status){
	rtn.server_failure = false;
} else {
	rtn.server_failure = true;
}

//加上这句话，将本步检测的结果返回给工具。
JSON.stringify(rtn);','',4);
CREATE TABLE test_tbl (txt_fld TEXT, num_fld NUMERIC, blob_fld BLOB);
COMMIT;
