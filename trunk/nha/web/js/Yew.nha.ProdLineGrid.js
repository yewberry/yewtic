Ext.namespace('Yew.nha');

Yew.nha.ProdLineGrid = Ext.extend(Ext.grid.EditorGridPanel, {
	urls : {
		getRecords : 'etc/production.json'
	}

	, constructor : function(config) {
		var urls = this.urls;
		
		var alertFunc = function(val){
	        if(val < 7){
	            return '<span style="color:green;">' + val + '</span>';
	        }else{
	            return '<span style="color:red;">' + val + '</span>';
	        }
	        return val;
	    }
		
		var cols = [];
		cols.push({
			id: 'ext'
			, header: '缺陷类别'
			, dataIndex: 'defect_name'
		});
		var prodCols = Yew.gv.prodCols;
		for(var i=0; i<prodCols.length; i++){
			var col = prodCols[i];
			col.editor = new Ext.form.NumberField({allowBlank : true});
			col.renderer = alertFunc;
			col.align = 'right';
			col.width = 80;
			cols.push(col);
		}
		
		var cm = new Ext.grid.ColumnModel({
	        defaults: {
	            sortable: true           
	        }
			, columns : cols
		});
		
		var flds = [];
		flds.push('defect_type');
		flds.push('defect_name');
		for(var i=0; i<prodCols.length; i++){
			var col = prodCols[i];
			flds.push(col.dataIndex);
		}

		var store = new Ext.data.JsonStore({
			url : urls.getRecords
		    , root: 'rows'
		    , fields: flds
		});
		
		var cfg = Ext.applyIf(config || {},{
	        store: store
	        , cm: cm
	        , clicksToEdit: 1
			, autoExpandColumn: 'ext'
			, autoExpandMin: 80
			, title: config.clientName + '生产线退件登记'
		});
		Yew.nha.ProdLineGrid.superclass.constructor.apply(this, [cfg]);
		
		this.on('afterlayout', function(o){
			o.getStore().reload();
		});
	}
});
