Ext.namespace('Yew.nha');

Yew.nha.Histogram = Ext.extend(Ext.Panel, {
	urls : {
		getRecords : 'etc/production.json'
	}
	, constructor : function(config) {
    var store = new Ext.data.JsonStore({
        fields:['name', 'visits', 'views'],
        data: [
            {name:'织带脏', visits: 12, views: 3000000},
            {name:'织带起毛', visits: 4, views: 3500000},
            {name:'织带划伤', visits: 34, views: 4000000},
            {name:'织带色差', visits: 12, views: 4200000},
            {name:'织带用错', visits: 3, views: 4500000},
            {name:'织带偏长', visits: 5, views: 5800000},
            {name:'织带偏短', visits: 22, views: 6000000},
            {name:'织带导套断', visits: 5, views: 7500000}
        ]
    });

		var cfg = Ext.applyIf(config || {},{
			frame:true,
			items: [{
				layout: 'hbox'
				, items: [{
					layout: 'form'
					, items: {
						xtype: 'combo'
						, fieldLabel: '件号'
					}
				},{
					layout: 'form'
					, items: {
						xtype: 'datefield'
						, fieldLabel: '截止日期'
					}
				}]
			},{
		        iconCls:'chart',
		        title: '示意图',
		        frame:true,
		        layout:'fit',
		        width:500,
		        height:300,

		        items: {
		            xtype: 'columnchart',
		            store: store,
		            url:'js/lib/ext/resources/charts.swf',
		            xField: 'name',
		            yAxis: new Ext.chart.NumericAxis({
		                displayName: 'Visits',
		                labelRenderer : Ext.util.Format.numberRenderer('0,0')
		            }),
		            tipRenderer : function(chart, record, index, series){
		                if(series.yField == 'visits'){
		                    return Ext.util.Format.number(record.data.visits, '0,0') + ' visits in ' + record.data.name;
		                }else{
		                    return Ext.util.Format.number(record.data.views, '0,0') + ' page views in ' + record.data.name;
		                }
		            },
		            chartStyle: {
		                padding: 10,
		                animationEnabled: true,
		                font: {
		                    name: 'Tahoma',
		                    color: 0x444444,
		                    size: 11
		                },
		                dataTip: {
		                    padding: 5,
		                    border: {
		                        color: 0x99bbe8,
		                        size:1
		                    },
		                    background: {
		                        color: 0xDAE7F6,
		                        alpha: .9
		                    },
		                    font: {
		                        name: 'Tahoma',
		                        color: 0x15428B,
		                        size: 10,
		                        bold: true
		                    }
		                },
		                xAxis: {
		                    color: 0x69aBc8,
		                    majorTicks: {color: 0x69aBc8, length: 4},
		                    minorTicks: {color: 0x69aBc8, length: 2},
		                    majorGridLines: {size: 1, color: 0xeeeeee}
		                },
		                yAxis: {
		                    color: 0x69aBc8,
		                    majorTicks: {color: 0x69aBc8, length: 4},
		                    minorTicks: {color: 0x69aBc8, length: 2},
		                    majorGridLines: {size: 1, color: 0xdfe8f6}
		                }
		            },
		            series: [{
		                type:'column',
		                displayName: 'Visits',
		                yField: 'visits',
		                style: {
		                    color: 0x15428B
		                }
		            }]
		        }

			}]
		});
		Yew.nha.Histogram.superclass.constructor.apply(this, [cfg]);
	}
});