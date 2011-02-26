BEGIN TRANSACTION;
CREATE TABLE server (id TEXT PRIMARY KEY, ip TEXT, name TEXT, desc TEXT, usr TEXT, pwd TEXT);
CREATE TABLE test_tbl (txt_fld TEXT, num_fld NUMERIC, blob_fld BLOB);
COMMIT;