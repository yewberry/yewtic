/*
 * NHA
 * Copyright(c) 2008-2010 Yewberry Studio, yew1998@gmail.com
 * yew1998@gmail.com
 */

Ext.onReady(function() {
	Ext.QuickTips.init();
	
	var cfg = {
		layout: 'border'
		, items: [{
			region: 'north'
			, height: '24'
			, bodyStyle: 'background-color:#4E78B1;text-align:center'
			, split: false
			, html: '<p><font size="6"><b>南京奥托立夫退回品信息登记系统</b></font></p>'
		},{
			region: 'center'
			, layout: 'fit'
			, items: [{
				xtype: 'grouptabpanel'
				, id: 'groupTabPanel'
				, tabWidth: 150
				, activeGroup: 0
				, items : [{
					items: [{
						title: '通知'
						, iconCls : 'x-icon-tickets'
						, tabTip : '现实通知'
						, style : 'padding: 10px;'
						, items : [new Yew.nha.NoticePanel()]
					}]
				},{
					//mainItem : 0
					items : [{
						title : 'SVW'
						, layout : 'fit'
						, iconCls : 'x-icon-tickets'
						, tabTip : '上海大众'
						, style : 'padding: 10px;'
						, items : [new SampleGrid([0, 1, 2, 3, 4])]
					},{
						title : '生产线退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '上海大众生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : [
							new Yew.nha.ProdLineRegForm({
								clientName: '上海大众'
							})
						]
					},{
						title : '售后退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '上海大众售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					},{
						title : '生产线退件信息'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '上海大众生产线退件信息查询'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : [
							new Yew.nha.ProdLineGrid({
								clientName: '上海大众'
							})
						]
					},{
						title : '售后退件信息'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '上海大众售后退件信息查询'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					}]
				},{
					expanded : false
					, items : [{
						title : 'DPCA'
						, iconCls : 'x-icon-configuration'
						, tabTip : '神龙汽车'
						, style : 'padding: 10px;'
					},{
						title : '生产线退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '神龙汽车生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					},{
						title : '售后退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '神龙汽车售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					}]
				},{
					expanded : false
					, items : [{
						title : 'SGM'
						, iconCls : 'x-icon-configuration'
						, tabTip : '上海通用'
						, style : 'padding: 10px;'
					},{
						title : '生产线退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '上海通用生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					},{
						title : '售后退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '上海通用售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					}]
				},{
					expanded : false
					, items : [{
						title : 'JMC'
						, iconCls : 'x-icon-configuration'
						, tabTip : '江铃汽车'
						, style : 'padding: 10px;'
					},{
						title : '生产线退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '江铃汽车生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					},{
						title : '售后退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '江铃汽车售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					}]
				},{
					expanded : false
					, items : [{
						title : 'DYK'
						, iconCls : 'x-icon-configuration'
						, tabTip : '起亚汽车'
						, style : 'padding: 10px;'
					},{
						title : '生产线退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '起亚汽车生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					},{
						title : '售后退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '起亚汽车售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					}]
				},{
					expanded : false
					, items : [{
						title : 'CHERY'
						, iconCls : 'x-icon-configuration'
						, tabTip : '奇瑞汽车'
						, style : 'padding: 10px;'
					},{
						title : '生产线退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '奇瑞汽车生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					},{
						title : '售后退件信息登记'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '奇瑞汽车售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : []
					}]
				},{
					expanded : true
					, items : [{
						title : '统计'
						, iconCls : 'x-icon-configuration'
						, tabTip : '统计'
						, style : 'padding: 10px;'
					},{
						title : '分件号统计-柱状图'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '奇瑞汽车生产线退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : [new Yew.nha.Histogram()]
					},{
						title : '退件数量统计-曲线图'
						, iconCls : 'x-icon-subscriptions'
						, tabTip : '奇瑞汽车售后退件信息登记'
						, style : 'padding: 10px;'
						, layout : 'fit'
						, items : [new Yew.nha.LineGraph()]
					}]
				}]
			}]
		}]

	};
	var viewport = new Ext.Viewport(cfg);

});
