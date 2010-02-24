Ext.namespace('Yew.nha');

Yew.nha.NoticePanel = Ext.extend(Ext.list.ListView, {
	urls: {
		getNotices: 'etc/notices.json'
	}
	, constructor: function(config){
		var urls = this.urls;
		var store = new Ext.data.JsonStore({
			url: urls.getNotices
		    , root: 'rows'
		    , fields: [
		        'title', 'post_by', 'view_count',
		        {name:'post_dt', type:'date', dateFormat:'timestamp'}
		    ]
		});
				
		var cfg = Ext.applyIf(config || {},{
			store: store
			, frame: true
		    , multiSelect: true
		    , emptyText: 'No images to display'
		    , reserveScrollOffset: true
		    , columns: [{
		    	header: '标题'
		        , width: .5
		        , dataIndex: 'title'
		    },{
		    	header: '提交人'
		        , width: .2
		        , dataIndex: 'post_by'
		    },{
		        header: '浏览次数'
		        , width: .1
		        , dataIndex: 'view_count'
		        //, tpl: '{view_count:fileSize}' // format using Ext.util.Format.fileSize()
		        , align: 'right'
		    },{
		        header: '提交日期'
		        , width: .2
		        , dataIndex: 'post_dt'
		        , tpl: '{post_dt:date("m-d h:i a")}'
		    }]
		});
		Yew.nha.NoticePanel.superclass.constructor.apply(this, [cfg]);

		this.on('render', function(o){
			o.getStore().load();
		});
	}
});