(function(self, $){
    self.main = function(){
        self.checkLogin();
    };
    
    self.checkLogin = function(){
        yewtic.logInfo('检查是否登录...');
        var a = $('a[href="login.php"]');
        if (a.length == 1){
	        yewtic.logInfo('尚未登录');
	        yewtic.setProperty('nextStep', 'Yew.login()');
	        parent.location = a[0].href;
        } else {
	        yewtic.logInfo('已登录');
	        Yew.getPosts();
        }
    };
    
    self.login = function(){
        yewtic.logInfo('登录中...');
        var usr = $('input[name="pwuser"]')[0];
        var pwd = $('input[name="pwpwd"]')[0];
        var sub = $('input[type="submit"]')[0];
        usr.value = 'yew98';
        pwd.value = 'yewyew';
        yewtic.setProperty('nextStep', 'Yew.waitRedirect()');
        yewtic.logInfo('等待跳转...');
        sub.click();
    };
    
    self.waitRedirect = function(){
        yewtic.logInfo('等待中...');
        yewtic.setProperty('nextStep', 'Yew.getPosts()');
    };
    
    self.getPosts = function(){
        yewtic.logInfo('获取帖子列表...');
        var posts = $('tr.tr3,tr.t_one');
        yewtic.logInfo('疑似发现 ' + posts.length + ' 个帖子。');
        var arr = [];
        var len = posts.length-1;//skip the last post by 赞助网站
        for (var i=0; i<len; i++){
	        var tds = $('td', posts[i]);
	        if(tds.length != 6){
		        continue;
	        }
	        var o = {};
	        //o.idx = i;
	        var h = tds[0];
	        var post = tds[1];
	        var post_cata = $('a', post)[0];
	        if (post_cata != null){
		        var t = post_cata.innerHTML;
		        if (t.indexOf('[')!=0 || t=='[公告]' || t=="[其他]"){
			        continue;
		        }
		        if (post_cata.childNodes.length == 3){
			        o.cata = post_cata.childNodes[1].innerHTML;
		        } else {
			        o.cata = jQuery.trim( t.substring(1, t.length-1) );
		        }
	        }
	        var postLink = $('H3', post)[0];
	        o.url = $('a', postLink)[0].href;
	        o.title = jQuery.trim( postLink.textContent );
	        o.rank = jQuery.trim( postLink.nextSibling.nodeValue);
	        if (o.rank.indexOf('(')!=0){
		        o.rank = '0';
	        } else {
		        o.rank = jQuery.trim(o.rank.substring(1, o.rank.length-1));
	        }
	        o.post_by = jQuery.trim( $('a',tds[2])[0].innerHTML );
	        o.post_dt = jQuery.trim( $('div',tds[2])[0].innerHTML );
	        o.reply_num = jQuery.trim( tds[3].firstChild.nodeValue );
	        o.view_num = jQuery.trim( tds[4].firstChild.nodeValue );
	        o.last_reply_dt = jQuery.trim( $('a',tds[5])[0].innerHTML );
	        arr.push(o);
        }
        yewtic.logInfo('提取 ' + arr.length + ' 个帖子。');
        
        if(arr.length > 0){
            var str = $.toJSON(arr);
            yewtic.procPostList(str);
            yewtic.openSubTabs(str, 'Yew.procPost()', 3);
        }
    };
    
    self.procPost = function(){
        var arr = $("a:contains('点击下载')");
        var url = yewtic.getProperty('url');
        yewtic.logInfo('发现 ' + arr.length + ' 首歌。'+url);
        var songs = [];
        for(var i=0; i<arr.length; i++){
            songs[i] = arr[i].href;
        }
        if(songs.length > 0){
            var s = $.toJSON(songs);
            yewtic.setProperty('p_songs', s);
            Yew.procMusic(0);
        }
    };
    
    self.procMusic = function(n){
        var s = yewtic.getProperty('p_songs');
        eval('var arr = ' + s);
        if(n < arr.length){
            yewtic.setProperty('nextStep', 'Yew.procDownloadConfirm(' + n + ')');
            parent.location = arr[n];
        } else {
            yewtic.logInfo('Find:'+s);
        }
    };
    
    self.procDownloadConfirm = function(n){
        var arr = $("a:contains('同意请点击获得下载地址')");
        if(arr.length == 1){
            yewtic.setProperty('nextStep', 'Yew.procDownloadUrl(' + n + ')');
            parent.location = arr[0].href;
        } else {
            yewtic.logError("未在下载确认页面找到确认链接。");
        }
    };
    
    self.procDownloadUrl = function(n){
        var arr = $("a:contains('右键另存')");
        
        var s = yewtic.getProperty('p_songs');
        eval('var _a = ' + s);
        _a[n] = arr[0].href;
        s = $.toJSON(_a);
        yewtic.setProperty('p_songs', s);
        
        Yew.procMusic(++n);
    };
    
})(Yew, jQuery);