(function(self, $){
    self.main = function(){
        self.checkLogin();
    };
    
    self.checkLogin = function(){
        yewtic.logInfo('����Ƿ��¼...');
        var a = $('a[href="login.php"]');
        if (a.length == 1){
	        yewtic.logInfo('��δ��¼');
	        yewtic.setProperty('nextStep', 'Yew.login()');
	        parent.location = a[0].href;
        } else {
	        yewtic.logInfo('�ѵ�¼');
	        Yew.getPosts();
        }
    };
    
    self.login = function(){
        yewtic.logInfo('��¼��...');
        var usr = $('input[name="pwuser"]')[0];
        var pwd = $('input[name="pwpwd"]')[0];
        var sub = $('input[type="submit"]')[0];
        usr.value = 'yew98';
        pwd.value = 'yewyew';
        yewtic.setProperty('nextStep', 'Yew.waitRedirect()');
        yewtic.logInfo('�ȴ���ת...');
        sub.click();
    };
    
    self.waitRedirect = function(){
        yewtic.logInfo('�ȴ���...');
        yewtic.setProperty('nextStep', 'Yew.getPosts()');
    };
    
    self.getPosts = function(){
        yewtic.logInfo('��ȡ�����б�...');
        var posts = $('tr.tr3,tr.t_one');
        yewtic.logInfo('���Ʒ��� ' + posts.length + ' �����ӡ�');
        var arr = [];
        var len = posts.length-1;//skip the last post by ������վ
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
		        if (t.indexOf('[')!=0 || t=='[����]' || t=="[����]"){
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
        yewtic.logInfo('��ȡ ' + arr.length + ' �����ӡ�');
        var s = $.toJSON(arr);
        yewtic.procPostLists(s);
        
        yewtic.setProperty('posts', s);
        self.getMusic(0);
    };
    
    self.getMusic = function(idx){
        var s = yewtic.getProperty('posts');
        eval('var o = ' + s);
        
        if(idx < o.length)
            yewtic.setProperty('nextStep', 'Yew.getMusic(' + (idx+1) + ')');
        else
            yewtic.removeProperty('nextStep');
        
        parent.location.reload();
    };
})(Yew, jQuery);