#pragma once

#include "redis_db.h"
#include "redis_metadata.h"

#include <string>
#include <vector>

namespace Redis {

class BitmapString : public Database {
 public:
  BitmapString(Engine::Storage *storage, const std::string &ns) : Database(storage, ns) {}
  rocksdb::Status GetBit(const std::string &string_value, uint32_t offset, bool *bit);
  rocksdb::Status SetBit(const Slice &ns_key, std::string *raw_value, uint32_t offset, int new_bit, bool *old_bit);
  rocksdb::Status BitCount(const std::string &string_value, int start, int stop, uint32_t *cnt);
  rocksdb::Status BitPos(const std::string &string_value, bool bit, int start, int stop, bool stop_given, int *pos);
 private:
  size_t redisPopcount(unsigned char *p, long count);
  long redisBitpos(unsigned char *c, unsigned long count, int bit);
};

}  // namespace Redis
