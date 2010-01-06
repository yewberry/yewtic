Yew = {
    getChildrenByTagName: function(tagName,context){
        var cn = context.childNodes;
        var arr = [];
        for(var i=0; i<cn.length; i++){
            var n = cn[i];
            if(n.localName == tagName)
            	arr.push(n);
        }
        return arr;
    }
    , getChildByIndex: function(idx, context){
        if(idx < 0)return null;
        var cn = context.childNodes;
        var c = -1;
        for(var i=0; i<cn.length; i++){
            var n = cn[i];
            if(n.nodeType != 1)continue;//not Element
            else c++;
            if(c == idx)return n;
        }
        return null;
    }
}