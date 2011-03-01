BEGIN TRANSACTION;
CREATE TABLE server (id TEXT PRIMARY KEY, ip TEXT, name TEXT, desc TEXT, usr TEXT, pwd TEXT, active NUMERIC, ui_scene_pos TEXT);
CREATE TABLE test_tbl (txt_fld TEXT, num_fld NUMERIC, blob_fld BLOB);
INSERT INTO server VALUES('1ecc4cfb810146eaa6cc78ec5c157994','172.28.13.18','ADC Server','This is ADC Server','euap','euap','false','0.0,0.0');
INSERT INTO server VALUES('615ffb16551d42b39b8672253428630e','172.28.13.16','MAS Server','This is MAS Server','mas','mas','false','0.0,0.0');
COMMIT;