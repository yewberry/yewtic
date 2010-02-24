Ext.namespace('Yew.nha');

Yew.nha.ProdLineRegForm = Ext.extend(Ext.form.FormPanel, {
	urls : {
		save : 'etc/production.json'
	}
	, constructor : function(config) {
		var urls = this.urls;
		var cfg = Ext.applyIf(config || {},{
			title: config.clientName + '生产线退件登记'
			, frame: true
			, labelWidth: 80
			, items: [{
				layout: 'column'
				, items: [{
					columnWidth: 1.0
					, html: '&nbsp;'
				}, {
					layout: 'form'
					, width: 250
					, items: {
						fieldLabel: '流水号'
						, xtype: 'textfield'
					}
				}]
			},{
				xtype: 'fieldset'
				, title: '客户&产品'
				, layout: 'table'
				, layoutConfig: {
				    columns: 3
				}
				, items: [{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '厂商名称'
						, xtype: 'textfield'
					}
				},{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '厂商ID'
						, xtype: 'textfield'
					}
				},{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '产品名称'
						, xtype: 'textfield'
					}
				},{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '件号'
						, xtype: 'textfield'
					}
				},{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '生产日期'
						, xtype: 'datefield'
					}
				}]
			},{
				xtype: 'fieldset'
				, title: '产品缺陷'
				, layout: 'table'
				, layoutConfig: {
				    columns: 3
				}
				, items: [{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '不良类型'
						, xtype: 'combo'
					}
				},{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '数量'
						, xtype: 'numberfield'
					}
				},{
					layout: 'form'
					, bodyStyle:'padding-right:25px'
					, items: {
						fieldLabel: '处理办法'
						, xtype: 'textfield'
					}
				}]
			},{
				xtype: 'fieldset'
				, title: '填制信息'
				, layout: 'table'
				, layoutConfig: {
				    columns: 2
				}
			    , defaults: {
			        bodyStyle:'padding-right:25px'
			    }
				, items: [{
					layout: 'form'
					, items: {
						fieldLabel: '填写人'
						, xtype: 'textfield'
					}
				},{
					layout: 'form'
					, items: {
						fieldLabel: '填写时间'
						, xtype: 'datefield'
					}
				},{
					layout: 'form'
					, items: {
						fieldLabel: '备注1'
						, xtype: 'textarea'
						, width: 200
					}
				},{
					layout: 'form'
					, items: {
						fieldLabel: '备注2'
						, xtype: 'textarea'
						, width: 200
					}
				}]
			},{
				layout: 'column'
				, items: [{
					columnWidth: .5
					, html: '&nbsp;'
				},{
					xtype: 'button'
					, text: '提交'
					, style: 'margin-right: 10px'
					, width: 150
					, height: 30
				},{
					xtype: 'button'
					, text: '清空'
					, width: 150
					, height: 30
				},{
					columnWidth: .5
					, html: '&nbsp;'
				}]
			}]
		});
		Yew.nha.ProdLineRegForm.superclass.constructor.apply(this, [cfg]);
	}
});
