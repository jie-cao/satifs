//
// Created by Jie Cao on 7/31/20.
//

#include "rocksdb_store.h"

void init() {
    DB* db;
    Options db_options;
    // Optimize RocksDB. This is the easiest way to get RocksDB to perform well
    db_options.IncreaseParallelism();
    db_options.OptimizeLevelStyleCompaction();
    std::cout<<"start ";
    // create the DB if it's not already present
    db_options.create_if_missing = true;
    std::cout<<"hello";

    // open DB
    Status s = DB::Open(db_options, "/tmp/rocksdb_simple_example", &db);
    assert(s.ok());
    // Put key-value
    s = db->Put(WriteOptions(), "key1", "value");
    assert(s.ok());

    std::string value;
    // get value
    s = db->Get(ReadOptions(), "key1", &value);
}
