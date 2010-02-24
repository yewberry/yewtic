Ext.namespace('Yew.nha');

Yew.nha.LineGraph = Ext.extend(Ext.Panel, {
	urls : {
		getRecords : 'etc/production.json'
	}
	, constructor : function(config) {
    var store = new Ext.data.JsonStore({
        fields:['name', 'visits', 'views'],
        data: [
            {name:'09年1月', visits: 60, views: 3000000},
            {name:'09年2月', visits: 36, views: 3500000},
            {name:'09年3月', visits: 70, views: 4000000},
            {name:'09年4月', visits: 47, views: 4200000},
            {name:'09年5月', visits: 35, views: 4500000},
            {name:'09年6月', visits: 24, views: 5800000},
            {name:'09年7月', visits: 22, views: 6000000},
            {name:'09年8月', visits: 18, views: 7500000},
            {name:'09年9月', visits: 18, views: 7500000},
            {name:'09年10月', visits: 18, views: 7500000},
            {name:'09年11月', visits: 18, views: 7500000},
            {name:'09年12月', visits: 18, views: 7500000}
        ]
    });


		var cfg = Ext.applyIf(config || {},{
			frame:true,
			items: [{
				layout: 'hbox'
				, items: [{
					layout: 'form'
					, items: {
						xtype: 'datefield'
						, fieldLabel: '开始日期'
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
		                type:'line',
		                displayName: 'Visits',
		                yField: 'visits',
		                style: {
		                    color: 0x15428B
		                }
		            }]
		        }

			}]
		});
		Yew.nha.LineGraph.superclass.constructor.apply(this, [cfg]);
	}
});