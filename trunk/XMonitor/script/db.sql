BEGIN TRANSACTION;
CREATE TABLE server (id TEXT PRIMARY KEY, ip TEXT, name TEXT, desc TEXT, usr TEXT, pwd TEXT, active NUMERIC, ui_scene_pos TEXT, status NUMERIC, step_status TEXT);
CREATE TABLE step (id TEXT PRIMARY KEY, svr_id TEXT, name TEXT, desc TEXT, cmd TEXT, script TEXT, cmd_result TEXT, seq NUMERIC, usr TEXT, pwd TEXT, type INTEGER);
CREATE TABLE test_tbl (txt_fld TEXT, num_fld NUMERIC, blob_fld BLOB);
INSERT INTO server VALUES('1ecc4cfb810146eaa6cc78ec5c157994','172.28.13.18','ADC Server','This is ADC Server','euap','euap','false','0.0,0.0','false','');
INSERT INTO server VALUES('615ffb16551d42b39b8672253428630e','172.28.13.16','MAS Server','This is MAS Server','mas','mas','false','0.0,0.0','false','');
COMMIT;