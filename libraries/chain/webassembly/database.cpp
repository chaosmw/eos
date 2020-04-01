#include <eosio/chain/webassembly/interface.hpp>

namespace eosio { namespace chain { namespace webassembly {
   /**
    * interface for primary index
    */
   int32_t interface::db_store_i64( uint64_t scope, uint64_t table, uint64_t payer, uint64_t id, legacy_array_ptr<const char> buffer ) {
      return context.db_store_i64( name(scope), name(table), account_name(payer), id, buffer.ref().data(), buffer.ref().size() );
   }
   void interface::db_update_i64( int32_t itr, uint64_t payer, legacy_array_ptr<const char> buffer ) {
      context.db_update_i64( itr, account_name(payer), buffer.ref().data(), buffer.ref().size() );
   }
   void interface::db_remove_i64( int32_t itr ) {
      context.db_remove_i64( itr );
   }
   int32_t interface::db_get_i64( int32_t itr, legacy_array_ptr<char> buffer ) {
      return context.db_get_i64( itr, buffer.ref().data(), buffer.ref().size() );
   }
   int32_t interface::db_next_i64( int32_t itr, legacy_ptr<uint64_t> primary ) {
      return context.db_next_i64(itr, primary.ref());
   }
   int32_t interface::db_previous_i64( int32_t itr, legacy_ptr<uint64_t> primary ) {
      return context.db_previous_i64(itr, primary.ref());
   }
   int32_t interface::db_find_i64( uint64_t code, uint64_t scope, uint64_t table, uint64_t id ) {
      return context.db_find_i64( name(code), name(scope), name(table), id );
   }
   int32_t interface::db_lowerbound_i64( uint64_t code, uint64_t scope, uint64_t table, uint64_t id ) {
      return context.db_lowerbound_i64( name(code), name(scope), name(table), id );
   }
   int32_t interface::db_upperbound_i64( uint64_t code, uint64_t scope, uint64_t table, uint64_t id ) {
      return context.db_upperbound_i64( name(code), name(scope), name(table), id );
   }
   int32_t interface::db_end_i64( uint64_t code, uint64_t scope, uint64_t table ) {
      return context.db_end_i64( name(code), name(scope), name(table) );
   }

   /**
    * interface for uint64_t secondary
    */
   int32_t interface::db_idx64_store( uint64_t scope, uint64_t table, uint64_t payer, uint64_t id, legacy_ptr<const uint64_t> secondary ) {
      return context.idx64.store( scope, table, account_name(payer), id, secondary.ref() );
   }
   void interface::db_idx64_update( int32_t iterator, uint64_t payer, legacy_ptr<const uint64_t> secondary ) {
      return context.idx64.update( iterator, account_name(payer), secondary.ref() );
   }
   void interface::db_idx64_remove( int32_t iterator ) {
      return context.idx64.remove( iterator );
   }
   int32_t interface::db_idx64_find_secondary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<const uint64_t> secondary, legacy_ptr<uint64_t> primary ) {
      return context.idx64.find_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx64_find_primary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<uint64_t> secondary, uint64_t primary ) {
      return context.idx64.find_primary(code, scope, table, secondary.ref(), primary);
   }
   int32_t interface::db_idx64_lowerbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<uint64_t> secondary, legacy_ptr<uint64_t> primary ) {
      return context.idx64.lowerbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx64_upperbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<uint64_t> secondary, legacy_ptr<uint64_t> primary ) {
      return context.idx64.upperbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx64_end( uint64_t code, uint64_t scope, uint64_t table ) {
      return context.idx64.end_secondary(code, scope, table);
   }
   int32_t interface::db_idx64_next( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx64.next_secondary(iterator, primary.ref());
   }
   int32_t interface::db_idx64_previous( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx64.previous_secondary(iterator, primary.ref());
   }


   /**
    * interface for uint128_t secondary
    */
   int32_t interface::db_idx128_store( uint64_t scope, uint64_t table, uint64_t payer, uint64_t id, legacy_ptr<const uint128_t> secondary ) {
      return context.idx128.store( scope, table, account_name(payer), id, secondary.ref() );
   }
   void interface::db_idx128_update( int32_t iterator, uint64_t payer, legacy_ptr<const uint128_t> secondary ) {
      return context.idx128.update( iterator, account_name(payer), secondary.ref() );
   }
   void interface::db_idx128_remove( int32_t iterator ) {
      return context.idx128.remove( iterator );
   }
   int32_t interface::db_idx128_find_secondary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<const uint128_t> secondary, legacy_ptr<uint64_t> primary ) {
      return context.idx128.find_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx128_find_primary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<uint128_t> secondary, uint64_t primary ) {
      return context.idx128.find_primary(code, scope, table, secondary.ref(), primary);
   }
   int32_t interface::db_idx128_lowerbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<uint128_t> secondary, legacy_ptr<uint64_t> primary ) {
      return context.idx128.lowerbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx128_upperbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<uint128_t> secondary, legacy_ptr<uint64_t> primary ) {
      return context.idx128.upperbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx128_end( uint64_t code, uint64_t scope, uint64_t table ) {
      return context.idx128.end_secondary(code, scope, table);
   }
   int32_t interface::db_idx128_next( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx128.next_secondary(iterator, primary.ref());
   }
   int32_t interface::db_idx128_previous( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx128.previous_secondary(iterator, primary.ref());
   }

   /**
    * interface for 256-bit interger secondary
    */
   inline static constexpr uint32_t idx256_array_size = 2;
   int32_t interface::db_idx256_store( uint64_t scope, uint64_t table, uint64_t payer, uint64_t id, legacy_array_ptr<const uint128_t> data ) {
      EOS_ASSERT( data.ref().size() == idx256_array_size,
                    db_api_exception,
                    "invalid size of secondary key array for idx256 : given ${given} bytes but expected ${expected} bytes",
                    ("given",data.ref().size())("expected", idx256_array_size) );
      return context.idx256.store(scope, table, account_name(payer), id, data.ref().data());
   }
   void interface::db_idx256_update( int32_t iterator, uint64_t payer, legacy_array_ptr<const uint128_t> data ) {
      EOS_ASSERT( data.ref().size() == idx256_array_size,
                    db_api_exception,
                    "invalid size of secondary key array for idx256 : given ${given} bytes but expected ${expected} bytes",
                    ("given",data.ref().size())("expected", idx256_array_size) );
      return context.idx256.update(iterator, account_name(payer), data.ref().data());
   }
   void interface::db_idx256_remove( int32_t iterator ) {
      return context.idx256.remove(iterator);
   }
   int32_t interface::db_idx256_find_secondary( uint64_t code, uint64_t scope, uint64_t table, legacy_array_ptr<const uint128_t> data, legacy_ptr<uint64_t> primary ) {
      EOS_ASSERT( data.ref().size() == idx256_array_size,
                    db_api_exception,
                    "invalid size of secondary key array for idx256 : given ${given} bytes but expected ${expected} bytes",
                    ("given",data.ref().size())("expected", idx256_array_size) );
      return context.idx256.find_secondary(code, scope, table, data.ref().data(), primary.ref());
   }
   int32_t interface::db_idx256_find_primary( uint64_t code, uint64_t scope, uint64_t table, legacy_array_ptr<uint128_t> data, uint64_t primary ) {
      EOS_ASSERT( data.ref().size() == idx256_array_size,
                    db_api_exception,
                    "invalid size of secondary key array for idx256 : given ${given} bytes but expected ${expected} bytes",
                    ("given",data.ref().size())("expected", idx256_array_size) );
      return context.idx256.find_primary(code, scope, table, data.ref().data(), primary);
   }
   int32_t interface::db_idx256_lowerbound( uint64_t code, uint64_t scope, uint64_t table, legacy_array_ptr<uint128_t> data, legacy_ptr<uint64_t> primary ) {
      EOS_ASSERT( data.ref().size() == idx256_array_size,
                    db_api_exception,
                    "invalid size of secondary key array for idx256 : given ${given} bytes but expected ${expected} bytes",
                    ("given",data.ref().size())("expected", idx256_array_size) );
      return context.idx256.lowerbound_secondary(code, scope, table, data.ref().data(), primary.ref());
   }
   int32_t interface::db_idx256_upperbound( uint64_t code, uint64_t scope, uint64_t table, legacy_array_ptr<uint128_t> data, legacy_ptr<uint64_t> primary ) {
      EOS_ASSERT( data.ref().size() == idx256_array_size,
                    db_api_exception,
                    "invalid size of secondary key array for idx256 : given ${given} bytes but expected ${expected} bytes",
                    ("given",data.ref().size())("expected", idx256_array_size) );
      return context.idx256.upperbound_secondary(code, scope, table, data.ref().data(), primary.ref());
   }
   int32_t interface::db_idx256_end( uint64_t code, uint64_t scope, uint64_t table ) {
      return context.idx256.end_secondary(code, scope, table);
   }
   int32_t interface::db_idx256_next( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx256.next_secondary(iterator, primary.ref());
   }
   int32_t interface::db_idx256_previous( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx256.previous_secondary(iterator, primary.ref());
   }

   /**
    * interface for double secondary
    */
   int32_t interface::db_idx_double_store( uint64_t scope, uint64_t table, uint64_t payer, uint64_t id, legacy_ptr<const float64_t> secondary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_double.store( scope, table, account_name(payer), id, secondary.ref() );
   }
   void interface::db_idx_double_update( int32_t iterator, uint64_t payer, legacy_ptr<const float64_t> secondary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_double.update( iterator, account_name(payer), secondary.ref() );
   }
   void interface::db_idx_double_remove( int32_t iterator ) {
      return context.idx_double.remove( iterator );
   }
   int32_t interface::db_idx_double_find_secondary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<const float64_t> secondary, legacy_ptr<uint64_t> primary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_double.find_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx_double_find_primary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<float64_t> secondary, uint64_t primary ) {
      return context.idx_double.find_primary(code, scope, table, secondary.ref(), primary);
   }
   int32_t interface::db_idx_double_lowerbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<float64_t> secondary, legacy_ptr<uint64_t> primary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_double.lowerbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx_double_upperbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<float64_t> secondary, legacy_ptr<uint64_t> primary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_double.upperbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx_double_end( uint64_t code, uint64_t scope, uint64_t table ) {
      return context.idx_double.end_secondary(code, scope, table);
   }
   int32_t interface::db_idx_double_next( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx_double.next_secondary(iterator, primary.ref());
   }
   int32_t interface::db_idx_double_previous( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx_double.previous_secondary(iterator, primary.ref());
   }

   /**
    * interface for long double secondary
    */
   int32_t interface::db_idx_long_double_store( uint64_t scope, uint64_t table, uint64_t payer, uint64_t id, legacy_ptr<const float128_t> secondary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_long_double.store( scope, table, account_name(payer), id, secondary.ref() );
   }
   void interface::db_idx_long_double_update( int32_t iterator, uint64_t payer, legacy_ptr<const float128_t> secondary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_long_double.update( iterator, account_name(payer), secondary.ref() );
   }
   void interface::db_idx_long_double_remove( int32_t iterator ) {
      return context.idx_long_double.remove( iterator );
   }
   int32_t interface::db_idx_long_double_find_secondary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<const float128_t> secondary, legacy_ptr<uint64_t> primary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_long_double.find_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx_long_double_find_primary( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<float128_t> secondary, uint64_t primary ) {
      return context.idx_long_double.find_primary(code, scope, table, secondary.ref(), primary);
   }
   int32_t interface::db_idx_long_double_lowerbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<float128_t> secondary, legacy_ptr<uint64_t> primary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_long_double.lowerbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx_long_double_upperbound( uint64_t code, uint64_t scope, uint64_t table, legacy_ptr<float128_t> secondary, legacy_ptr<uint64_t> primary ) {
//      EOS_ASSERT( !softfloat_api::is_nan( secondary ), transaction_exception, "NaN is not an allowed value for a secondary key" );
      return context.idx_long_double.upperbound_secondary(code, scope, table, secondary.ref(), primary.ref());
   }
   int32_t interface::db_idx_long_double_end( uint64_t code, uint64_t scope, uint64_t table ) {
      return context.idx_long_double.end_secondary(code, scope, table);
   }
   int32_t interface::db_idx_long_double_next( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx_long_double.next_secondary(iterator, primary);
   }
   int32_t interface::db_idx_long_double_previous( int32_t iterator, legacy_ptr<uint64_t> primary ) {
      return context.idx_long_double.previous_secondary(iterator, primary);
   }
}}} // ns eosio::chain::webassembly
