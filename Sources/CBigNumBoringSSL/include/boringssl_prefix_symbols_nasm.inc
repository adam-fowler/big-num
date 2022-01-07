; Copyright (c) 2018, Google Inc.
;
; Permission to use, copy, modify, and/or distribute this software for any
; purpose with or without fee is hereby granted, provided that the above
; copyright notice and this permission notice appear in all copies.
;
; THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
; WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
; MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
; SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
; WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
; OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
; CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

; 32-bit Windows adds underscores to C functions, while 64-bit Windows does not.
%ifidn __OUTPUT_FORMAT__, win32
%xdefine _AES_cbc_encrypt _ %+ BORINGSSL_PREFIX %+ _AES_cbc_encrypt
%xdefine _AES_cfb128_encrypt _ %+ BORINGSSL_PREFIX %+ _AES_cfb128_encrypt
%xdefine _AES_ctr128_encrypt _ %+ BORINGSSL_PREFIX %+ _AES_ctr128_encrypt
%xdefine _AES_decrypt _ %+ BORINGSSL_PREFIX %+ _AES_decrypt
%xdefine _AES_ecb_encrypt _ %+ BORINGSSL_PREFIX %+ _AES_ecb_encrypt
%xdefine _AES_encrypt _ %+ BORINGSSL_PREFIX %+ _AES_encrypt
%xdefine _AES_ofb128_encrypt _ %+ BORINGSSL_PREFIX %+ _AES_ofb128_encrypt
%xdefine _AES_set_decrypt_key _ %+ BORINGSSL_PREFIX %+ _AES_set_decrypt_key
%xdefine _AES_set_encrypt_key _ %+ BORINGSSL_PREFIX %+ _AES_set_encrypt_key
%xdefine _AES_unwrap_key _ %+ BORINGSSL_PREFIX %+ _AES_unwrap_key
%xdefine _AES_unwrap_key_padded _ %+ BORINGSSL_PREFIX %+ _AES_unwrap_key_padded
%xdefine _AES_wrap_key _ %+ BORINGSSL_PREFIX %+ _AES_wrap_key
%xdefine _AES_wrap_key_padded _ %+ BORINGSSL_PREFIX %+ _AES_wrap_key_padded
%xdefine _BIO_append_filename _ %+ BORINGSSL_PREFIX %+ _BIO_append_filename
%xdefine _BIO_callback_ctrl _ %+ BORINGSSL_PREFIX %+ _BIO_callback_ctrl
%xdefine _BIO_clear_flags _ %+ BORINGSSL_PREFIX %+ _BIO_clear_flags
%xdefine _BIO_clear_retry_flags _ %+ BORINGSSL_PREFIX %+ _BIO_clear_retry_flags
%xdefine _BIO_copy_next_retry _ %+ BORINGSSL_PREFIX %+ _BIO_copy_next_retry
%xdefine _BIO_ctrl _ %+ BORINGSSL_PREFIX %+ _BIO_ctrl
%xdefine _BIO_ctrl_pending _ %+ BORINGSSL_PREFIX %+ _BIO_ctrl_pending
%xdefine _BIO_eof _ %+ BORINGSSL_PREFIX %+ _BIO_eof
%xdefine _BIO_find_type _ %+ BORINGSSL_PREFIX %+ _BIO_find_type
%xdefine _BIO_flush _ %+ BORINGSSL_PREFIX %+ _BIO_flush
%xdefine _BIO_free _ %+ BORINGSSL_PREFIX %+ _BIO_free
%xdefine _BIO_free_all _ %+ BORINGSSL_PREFIX %+ _BIO_free_all
%xdefine _BIO_get_data _ %+ BORINGSSL_PREFIX %+ _BIO_get_data
%xdefine _BIO_get_fp _ %+ BORINGSSL_PREFIX %+ _BIO_get_fp
%xdefine _BIO_get_init _ %+ BORINGSSL_PREFIX %+ _BIO_get_init
%xdefine _BIO_get_new_index _ %+ BORINGSSL_PREFIX %+ _BIO_get_new_index
%xdefine _BIO_get_retry_flags _ %+ BORINGSSL_PREFIX %+ _BIO_get_retry_flags
%xdefine _BIO_get_retry_reason _ %+ BORINGSSL_PREFIX %+ _BIO_get_retry_reason
%xdefine _BIO_get_shutdown _ %+ BORINGSSL_PREFIX %+ _BIO_get_shutdown
%xdefine _BIO_gets _ %+ BORINGSSL_PREFIX %+ _BIO_gets
%xdefine _BIO_indent _ %+ BORINGSSL_PREFIX %+ _BIO_indent
%xdefine _BIO_int_ctrl _ %+ BORINGSSL_PREFIX %+ _BIO_int_ctrl
%xdefine _BIO_meth_free _ %+ BORINGSSL_PREFIX %+ _BIO_meth_free
%xdefine _BIO_meth_new _ %+ BORINGSSL_PREFIX %+ _BIO_meth_new
%xdefine _BIO_meth_set_create _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_create
%xdefine _BIO_meth_set_ctrl _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_ctrl
%xdefine _BIO_meth_set_destroy _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_destroy
%xdefine _BIO_meth_set_gets _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_gets
%xdefine _BIO_meth_set_puts _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_puts
%xdefine _BIO_meth_set_read _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_read
%xdefine _BIO_meth_set_write _ %+ BORINGSSL_PREFIX %+ _BIO_meth_set_write
%xdefine _BIO_method_type _ %+ BORINGSSL_PREFIX %+ _BIO_method_type
%xdefine _BIO_new _ %+ BORINGSSL_PREFIX %+ _BIO_new
%xdefine _BIO_new_file _ %+ BORINGSSL_PREFIX %+ _BIO_new_file
%xdefine _BIO_new_fp _ %+ BORINGSSL_PREFIX %+ _BIO_new_fp
%xdefine _BIO_next _ %+ BORINGSSL_PREFIX %+ _BIO_next
%xdefine _BIO_number_read _ %+ BORINGSSL_PREFIX %+ _BIO_number_read
%xdefine _BIO_number_written _ %+ BORINGSSL_PREFIX %+ _BIO_number_written
%xdefine _BIO_pending _ %+ BORINGSSL_PREFIX %+ _BIO_pending
%xdefine _BIO_pop _ %+ BORINGSSL_PREFIX %+ _BIO_pop
%xdefine _BIO_ptr_ctrl _ %+ BORINGSSL_PREFIX %+ _BIO_ptr_ctrl
%xdefine _BIO_push _ %+ BORINGSSL_PREFIX %+ _BIO_push
%xdefine _BIO_puts _ %+ BORINGSSL_PREFIX %+ _BIO_puts
%xdefine _BIO_read _ %+ BORINGSSL_PREFIX %+ _BIO_read
%xdefine _BIO_read_asn1 _ %+ BORINGSSL_PREFIX %+ _BIO_read_asn1
%xdefine _BIO_read_filename _ %+ BORINGSSL_PREFIX %+ _BIO_read_filename
%xdefine _BIO_reset _ %+ BORINGSSL_PREFIX %+ _BIO_reset
%xdefine _BIO_rw_filename _ %+ BORINGSSL_PREFIX %+ _BIO_rw_filename
%xdefine _BIO_s_file _ %+ BORINGSSL_PREFIX %+ _BIO_s_file
%xdefine _BIO_seek _ %+ BORINGSSL_PREFIX %+ _BIO_seek
%xdefine _BIO_set_close _ %+ BORINGSSL_PREFIX %+ _BIO_set_close
%xdefine _BIO_set_data _ %+ BORINGSSL_PREFIX %+ _BIO_set_data
%xdefine _BIO_set_flags _ %+ BORINGSSL_PREFIX %+ _BIO_set_flags
%xdefine _BIO_set_fp _ %+ BORINGSSL_PREFIX %+ _BIO_set_fp
%xdefine _BIO_set_init _ %+ BORINGSSL_PREFIX %+ _BIO_set_init
%xdefine _BIO_set_retry_read _ %+ BORINGSSL_PREFIX %+ _BIO_set_retry_read
%xdefine _BIO_set_retry_reason _ %+ BORINGSSL_PREFIX %+ _BIO_set_retry_reason
%xdefine _BIO_set_retry_special _ %+ BORINGSSL_PREFIX %+ _BIO_set_retry_special
%xdefine _BIO_set_retry_write _ %+ BORINGSSL_PREFIX %+ _BIO_set_retry_write
%xdefine _BIO_set_shutdown _ %+ BORINGSSL_PREFIX %+ _BIO_set_shutdown
%xdefine _BIO_set_write_buffer_size _ %+ BORINGSSL_PREFIX %+ _BIO_set_write_buffer_size
%xdefine _BIO_should_io_special _ %+ BORINGSSL_PREFIX %+ _BIO_should_io_special
%xdefine _BIO_should_read _ %+ BORINGSSL_PREFIX %+ _BIO_should_read
%xdefine _BIO_should_retry _ %+ BORINGSSL_PREFIX %+ _BIO_should_retry
%xdefine _BIO_should_write _ %+ BORINGSSL_PREFIX %+ _BIO_should_write
%xdefine _BIO_snprintf _ %+ BORINGSSL_PREFIX %+ _BIO_snprintf
%xdefine _BIO_tell _ %+ BORINGSSL_PREFIX %+ _BIO_tell
%xdefine _BIO_test_flags _ %+ BORINGSSL_PREFIX %+ _BIO_test_flags
%xdefine _BIO_up_ref _ %+ BORINGSSL_PREFIX %+ _BIO_up_ref
%xdefine _BIO_vfree _ %+ BORINGSSL_PREFIX %+ _BIO_vfree
%xdefine _BIO_vsnprintf _ %+ BORINGSSL_PREFIX %+ _BIO_vsnprintf
%xdefine _BIO_wpending _ %+ BORINGSSL_PREFIX %+ _BIO_wpending
%xdefine _BIO_write _ %+ BORINGSSL_PREFIX %+ _BIO_write
%xdefine _BIO_write_all _ %+ BORINGSSL_PREFIX %+ _BIO_write_all
%xdefine _BIO_write_filename _ %+ BORINGSSL_PREFIX %+ _BIO_write_filename
%xdefine _BN_CTX_end _ %+ BORINGSSL_PREFIX %+ _BN_CTX_end
%xdefine _BN_CTX_free _ %+ BORINGSSL_PREFIX %+ _BN_CTX_free
%xdefine _BN_CTX_get _ %+ BORINGSSL_PREFIX %+ _BN_CTX_get
%xdefine _BN_CTX_new _ %+ BORINGSSL_PREFIX %+ _BN_CTX_new
%xdefine _BN_CTX_start _ %+ BORINGSSL_PREFIX %+ _BN_CTX_start
%xdefine _BN_GENCB_call _ %+ BORINGSSL_PREFIX %+ _BN_GENCB_call
%xdefine _BN_GENCB_free _ %+ BORINGSSL_PREFIX %+ _BN_GENCB_free
%xdefine _BN_GENCB_new _ %+ BORINGSSL_PREFIX %+ _BN_GENCB_new
%xdefine _BN_GENCB_set _ %+ BORINGSSL_PREFIX %+ _BN_GENCB_set
%xdefine _BN_MONT_CTX_copy _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_copy
%xdefine _BN_MONT_CTX_free _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_free
%xdefine _BN_MONT_CTX_new _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_new
%xdefine _BN_MONT_CTX_new_consttime _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_new_consttime
%xdefine _BN_MONT_CTX_new_for_modulus _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_new_for_modulus
%xdefine _BN_MONT_CTX_set _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_set
%xdefine _BN_MONT_CTX_set_locked _ %+ BORINGSSL_PREFIX %+ _BN_MONT_CTX_set_locked
%xdefine _BN_abs_is_word _ %+ BORINGSSL_PREFIX %+ _BN_abs_is_word
%xdefine _BN_add _ %+ BORINGSSL_PREFIX %+ _BN_add
%xdefine _BN_add_word _ %+ BORINGSSL_PREFIX %+ _BN_add_word
%xdefine _BN_asc2bn _ %+ BORINGSSL_PREFIX %+ _BN_asc2bn
%xdefine _BN_bin2bn _ %+ BORINGSSL_PREFIX %+ _BN_bin2bn
%xdefine _BN_bn2bin _ %+ BORINGSSL_PREFIX %+ _BN_bn2bin
%xdefine _BN_bn2bin_padded _ %+ BORINGSSL_PREFIX %+ _BN_bn2bin_padded
%xdefine _BN_bn2binpad _ %+ BORINGSSL_PREFIX %+ _BN_bn2binpad
%xdefine _BN_bn2cbb_padded _ %+ BORINGSSL_PREFIX %+ _BN_bn2cbb_padded
%xdefine _BN_bn2dec _ %+ BORINGSSL_PREFIX %+ _BN_bn2dec
%xdefine _BN_bn2hex _ %+ BORINGSSL_PREFIX %+ _BN_bn2hex
%xdefine _BN_bn2le_padded _ %+ BORINGSSL_PREFIX %+ _BN_bn2le_padded
%xdefine _BN_bn2mpi _ %+ BORINGSSL_PREFIX %+ _BN_bn2mpi
%xdefine _BN_clear _ %+ BORINGSSL_PREFIX %+ _BN_clear
%xdefine _BN_clear_bit _ %+ BORINGSSL_PREFIX %+ _BN_clear_bit
%xdefine _BN_clear_free _ %+ BORINGSSL_PREFIX %+ _BN_clear_free
%xdefine _BN_cmp _ %+ BORINGSSL_PREFIX %+ _BN_cmp
%xdefine _BN_cmp_word _ %+ BORINGSSL_PREFIX %+ _BN_cmp_word
%xdefine _BN_copy _ %+ BORINGSSL_PREFIX %+ _BN_copy
%xdefine _BN_count_low_zero_bits _ %+ BORINGSSL_PREFIX %+ _BN_count_low_zero_bits
%xdefine _BN_dec2bn _ %+ BORINGSSL_PREFIX %+ _BN_dec2bn
%xdefine _BN_div _ %+ BORINGSSL_PREFIX %+ _BN_div
%xdefine _BN_div_word _ %+ BORINGSSL_PREFIX %+ _BN_div_word
%xdefine _BN_dup _ %+ BORINGSSL_PREFIX %+ _BN_dup
%xdefine _BN_enhanced_miller_rabin_primality_test _ %+ BORINGSSL_PREFIX %+ _BN_enhanced_miller_rabin_primality_test
%xdefine _BN_equal_consttime _ %+ BORINGSSL_PREFIX %+ _BN_equal_consttime
%xdefine _BN_exp _ %+ BORINGSSL_PREFIX %+ _BN_exp
%xdefine _BN_free _ %+ BORINGSSL_PREFIX %+ _BN_free
%xdefine _BN_from_montgomery _ %+ BORINGSSL_PREFIX %+ _BN_from_montgomery
%xdefine _BN_gcd _ %+ BORINGSSL_PREFIX %+ _BN_gcd
%xdefine _BN_generate_prime_ex _ %+ BORINGSSL_PREFIX %+ _BN_generate_prime_ex
%xdefine _BN_get_u64 _ %+ BORINGSSL_PREFIX %+ _BN_get_u64
%xdefine _BN_get_word _ %+ BORINGSSL_PREFIX %+ _BN_get_word
%xdefine _BN_hex2bn _ %+ BORINGSSL_PREFIX %+ _BN_hex2bn
%xdefine _BN_init _ %+ BORINGSSL_PREFIX %+ _BN_init
%xdefine _BN_is_bit_set _ %+ BORINGSSL_PREFIX %+ _BN_is_bit_set
%xdefine _BN_is_negative _ %+ BORINGSSL_PREFIX %+ _BN_is_negative
%xdefine _BN_is_odd _ %+ BORINGSSL_PREFIX %+ _BN_is_odd
%xdefine _BN_is_one _ %+ BORINGSSL_PREFIX %+ _BN_is_one
%xdefine _BN_is_pow2 _ %+ BORINGSSL_PREFIX %+ _BN_is_pow2
%xdefine _BN_is_prime_ex _ %+ BORINGSSL_PREFIX %+ _BN_is_prime_ex
%xdefine _BN_is_prime_fasttest_ex _ %+ BORINGSSL_PREFIX %+ _BN_is_prime_fasttest_ex
%xdefine _BN_is_word _ %+ BORINGSSL_PREFIX %+ _BN_is_word
%xdefine _BN_is_zero _ %+ BORINGSSL_PREFIX %+ _BN_is_zero
%xdefine _BN_le2bn _ %+ BORINGSSL_PREFIX %+ _BN_le2bn
%xdefine _BN_lshift _ %+ BORINGSSL_PREFIX %+ _BN_lshift
%xdefine _BN_lshift1 _ %+ BORINGSSL_PREFIX %+ _BN_lshift1
%xdefine _BN_mask_bits _ %+ BORINGSSL_PREFIX %+ _BN_mask_bits
%xdefine _BN_mod_add _ %+ BORINGSSL_PREFIX %+ _BN_mod_add
%xdefine _BN_mod_add_quick _ %+ BORINGSSL_PREFIX %+ _BN_mod_add_quick
%xdefine _BN_mod_exp _ %+ BORINGSSL_PREFIX %+ _BN_mod_exp
%xdefine _BN_mod_exp2_mont _ %+ BORINGSSL_PREFIX %+ _BN_mod_exp2_mont
%xdefine _BN_mod_exp_mont _ %+ BORINGSSL_PREFIX %+ _BN_mod_exp_mont
%xdefine _BN_mod_exp_mont_consttime _ %+ BORINGSSL_PREFIX %+ _BN_mod_exp_mont_consttime
%xdefine _BN_mod_exp_mont_word _ %+ BORINGSSL_PREFIX %+ _BN_mod_exp_mont_word
%xdefine _BN_mod_inverse _ %+ BORINGSSL_PREFIX %+ _BN_mod_inverse
%xdefine _BN_mod_inverse_blinded _ %+ BORINGSSL_PREFIX %+ _BN_mod_inverse_blinded
%xdefine _BN_mod_inverse_odd _ %+ BORINGSSL_PREFIX %+ _BN_mod_inverse_odd
%xdefine _BN_mod_lshift _ %+ BORINGSSL_PREFIX %+ _BN_mod_lshift
%xdefine _BN_mod_lshift1 _ %+ BORINGSSL_PREFIX %+ _BN_mod_lshift1
%xdefine _BN_mod_lshift1_quick _ %+ BORINGSSL_PREFIX %+ _BN_mod_lshift1_quick
%xdefine _BN_mod_lshift_quick _ %+ BORINGSSL_PREFIX %+ _BN_mod_lshift_quick
%xdefine _BN_mod_mul _ %+ BORINGSSL_PREFIX %+ _BN_mod_mul
%xdefine _BN_mod_mul_montgomery _ %+ BORINGSSL_PREFIX %+ _BN_mod_mul_montgomery
%xdefine _BN_mod_pow2 _ %+ BORINGSSL_PREFIX %+ _BN_mod_pow2
%xdefine _BN_mod_sqr _ %+ BORINGSSL_PREFIX %+ _BN_mod_sqr
%xdefine _BN_mod_sqrt _ %+ BORINGSSL_PREFIX %+ _BN_mod_sqrt
%xdefine _BN_mod_sub _ %+ BORINGSSL_PREFIX %+ _BN_mod_sub
%xdefine _BN_mod_sub_quick _ %+ BORINGSSL_PREFIX %+ _BN_mod_sub_quick
%xdefine _BN_mod_word _ %+ BORINGSSL_PREFIX %+ _BN_mod_word
%xdefine _BN_mpi2bn _ %+ BORINGSSL_PREFIX %+ _BN_mpi2bn
%xdefine _BN_mul _ %+ BORINGSSL_PREFIX %+ _BN_mul
%xdefine _BN_mul_word _ %+ BORINGSSL_PREFIX %+ _BN_mul_word
%xdefine _BN_new _ %+ BORINGSSL_PREFIX %+ _BN_new
%xdefine _BN_nnmod _ %+ BORINGSSL_PREFIX %+ _BN_nnmod
%xdefine _BN_nnmod_pow2 _ %+ BORINGSSL_PREFIX %+ _BN_nnmod_pow2
%xdefine _BN_num_bits _ %+ BORINGSSL_PREFIX %+ _BN_num_bits
%xdefine _BN_num_bits_word _ %+ BORINGSSL_PREFIX %+ _BN_num_bits_word
%xdefine _BN_num_bytes _ %+ BORINGSSL_PREFIX %+ _BN_num_bytes
%xdefine _BN_one _ %+ BORINGSSL_PREFIX %+ _BN_one
%xdefine _BN_primality_test _ %+ BORINGSSL_PREFIX %+ _BN_primality_test
%xdefine _BN_print _ %+ BORINGSSL_PREFIX %+ _BN_print
%xdefine _BN_print_fp _ %+ BORINGSSL_PREFIX %+ _BN_print_fp
%xdefine _BN_pseudo_rand _ %+ BORINGSSL_PREFIX %+ _BN_pseudo_rand
%xdefine _BN_pseudo_rand_range _ %+ BORINGSSL_PREFIX %+ _BN_pseudo_rand_range
%xdefine _BN_rand _ %+ BORINGSSL_PREFIX %+ _BN_rand
%xdefine _BN_rand_range _ %+ BORINGSSL_PREFIX %+ _BN_rand_range
%xdefine _BN_rand_range_ex _ %+ BORINGSSL_PREFIX %+ _BN_rand_range_ex
%xdefine _BN_rshift _ %+ BORINGSSL_PREFIX %+ _BN_rshift
%xdefine _BN_rshift1 _ %+ BORINGSSL_PREFIX %+ _BN_rshift1
%xdefine _BN_set_bit _ %+ BORINGSSL_PREFIX %+ _BN_set_bit
%xdefine _BN_set_negative _ %+ BORINGSSL_PREFIX %+ _BN_set_negative
%xdefine _BN_set_u64 _ %+ BORINGSSL_PREFIX %+ _BN_set_u64
%xdefine _BN_set_word _ %+ BORINGSSL_PREFIX %+ _BN_set_word
%xdefine _BN_sqr _ %+ BORINGSSL_PREFIX %+ _BN_sqr
%xdefine _BN_sqrt _ %+ BORINGSSL_PREFIX %+ _BN_sqrt
%xdefine _BN_sub _ %+ BORINGSSL_PREFIX %+ _BN_sub
%xdefine _BN_sub_word _ %+ BORINGSSL_PREFIX %+ _BN_sub_word
%xdefine _BN_to_montgomery _ %+ BORINGSSL_PREFIX %+ _BN_to_montgomery
%xdefine _BN_uadd _ %+ BORINGSSL_PREFIX %+ _BN_uadd
%xdefine _BN_ucmp _ %+ BORINGSSL_PREFIX %+ _BN_ucmp
%xdefine _BN_usub _ %+ BORINGSSL_PREFIX %+ _BN_usub
%xdefine _BN_value_one _ %+ BORINGSSL_PREFIX %+ _BN_value_one
%xdefine _BN_zero _ %+ BORINGSSL_PREFIX %+ _BN_zero
%xdefine _CBB_add_asn1 _ %+ BORINGSSL_PREFIX %+ _CBB_add_asn1
%xdefine _CBB_add_asn1_bool _ %+ BORINGSSL_PREFIX %+ _CBB_add_asn1_bool
%xdefine _CBB_add_asn1_int64 _ %+ BORINGSSL_PREFIX %+ _CBB_add_asn1_int64
%xdefine _CBB_add_asn1_octet_string _ %+ BORINGSSL_PREFIX %+ _CBB_add_asn1_octet_string
%xdefine _CBB_add_asn1_oid_from_text _ %+ BORINGSSL_PREFIX %+ _CBB_add_asn1_oid_from_text
%xdefine _CBB_add_asn1_uint64 _ %+ BORINGSSL_PREFIX %+ _CBB_add_asn1_uint64
%xdefine _CBB_add_bytes _ %+ BORINGSSL_PREFIX %+ _CBB_add_bytes
%xdefine _CBB_add_space _ %+ BORINGSSL_PREFIX %+ _CBB_add_space
%xdefine _CBB_add_u16 _ %+ BORINGSSL_PREFIX %+ _CBB_add_u16
%xdefine _CBB_add_u16_length_prefixed _ %+ BORINGSSL_PREFIX %+ _CBB_add_u16_length_prefixed
%xdefine _CBB_add_u16le _ %+ BORINGSSL_PREFIX %+ _CBB_add_u16le
%xdefine _CBB_add_u24 _ %+ BORINGSSL_PREFIX %+ _CBB_add_u24
%xdefine _CBB_add_u24_length_prefixed _ %+ BORINGSSL_PREFIX %+ _CBB_add_u24_length_prefixed
%xdefine _CBB_add_u32 _ %+ BORINGSSL_PREFIX %+ _CBB_add_u32
%xdefine _CBB_add_u32le _ %+ BORINGSSL_PREFIX %+ _CBB_add_u32le
%xdefine _CBB_add_u64 _ %+ BORINGSSL_PREFIX %+ _CBB_add_u64
%xdefine _CBB_add_u64le _ %+ BORINGSSL_PREFIX %+ _CBB_add_u64le
%xdefine _CBB_add_u8 _ %+ BORINGSSL_PREFIX %+ _CBB_add_u8
%xdefine _CBB_add_u8_length_prefixed _ %+ BORINGSSL_PREFIX %+ _CBB_add_u8_length_prefixed
%xdefine _CBB_add_zeros _ %+ BORINGSSL_PREFIX %+ _CBB_add_zeros
%xdefine _CBB_cleanup _ %+ BORINGSSL_PREFIX %+ _CBB_cleanup
%xdefine _CBB_data _ %+ BORINGSSL_PREFIX %+ _CBB_data
%xdefine _CBB_did_write _ %+ BORINGSSL_PREFIX %+ _CBB_did_write
%xdefine _CBB_discard_child _ %+ BORINGSSL_PREFIX %+ _CBB_discard_child
%xdefine _CBB_finish _ %+ BORINGSSL_PREFIX %+ _CBB_finish
%xdefine _CBB_finish_i2d _ %+ BORINGSSL_PREFIX %+ _CBB_finish_i2d
%xdefine _CBB_flush _ %+ BORINGSSL_PREFIX %+ _CBB_flush
%xdefine _CBB_flush_asn1_set_of _ %+ BORINGSSL_PREFIX %+ _CBB_flush_asn1_set_of
%xdefine _CBB_init _ %+ BORINGSSL_PREFIX %+ _CBB_init
%xdefine _CBB_init_fixed _ %+ BORINGSSL_PREFIX %+ _CBB_init_fixed
%xdefine _CBB_len _ %+ BORINGSSL_PREFIX %+ _CBB_len
%xdefine _CBB_reserve _ %+ BORINGSSL_PREFIX %+ _CBB_reserve
%xdefine _CBB_zero _ %+ BORINGSSL_PREFIX %+ _CBB_zero
%xdefine _CBS_asn1_ber_to_der _ %+ BORINGSSL_PREFIX %+ _CBS_asn1_ber_to_der
%xdefine _CBS_asn1_bitstring_has_bit _ %+ BORINGSSL_PREFIX %+ _CBS_asn1_bitstring_has_bit
%xdefine _CBS_asn1_oid_to_text _ %+ BORINGSSL_PREFIX %+ _CBS_asn1_oid_to_text
%xdefine _CBS_contains_zero_byte _ %+ BORINGSSL_PREFIX %+ _CBS_contains_zero_byte
%xdefine _CBS_copy_bytes _ %+ BORINGSSL_PREFIX %+ _CBS_copy_bytes
%xdefine _CBS_data _ %+ BORINGSSL_PREFIX %+ _CBS_data
%xdefine _CBS_get_any_asn1 _ %+ BORINGSSL_PREFIX %+ _CBS_get_any_asn1
%xdefine _CBS_get_any_asn1_element _ %+ BORINGSSL_PREFIX %+ _CBS_get_any_asn1_element
%xdefine _CBS_get_any_ber_asn1_element _ %+ BORINGSSL_PREFIX %+ _CBS_get_any_ber_asn1_element
%xdefine _CBS_get_asn1 _ %+ BORINGSSL_PREFIX %+ _CBS_get_asn1
%xdefine _CBS_get_asn1_bool _ %+ BORINGSSL_PREFIX %+ _CBS_get_asn1_bool
%xdefine _CBS_get_asn1_element _ %+ BORINGSSL_PREFIX %+ _CBS_get_asn1_element
%xdefine _CBS_get_asn1_implicit_string _ %+ BORINGSSL_PREFIX %+ _CBS_get_asn1_implicit_string
%xdefine _CBS_get_asn1_int64 _ %+ BORINGSSL_PREFIX %+ _CBS_get_asn1_int64
%xdefine _CBS_get_asn1_uint64 _ %+ BORINGSSL_PREFIX %+ _CBS_get_asn1_uint64
%xdefine _CBS_get_bytes _ %+ BORINGSSL_PREFIX %+ _CBS_get_bytes
%xdefine _CBS_get_last_u8 _ %+ BORINGSSL_PREFIX %+ _CBS_get_last_u8
%xdefine _CBS_get_optional_asn1 _ %+ BORINGSSL_PREFIX %+ _CBS_get_optional_asn1
%xdefine _CBS_get_optional_asn1_bool _ %+ BORINGSSL_PREFIX %+ _CBS_get_optional_asn1_bool
%xdefine _CBS_get_optional_asn1_octet_string _ %+ BORINGSSL_PREFIX %+ _CBS_get_optional_asn1_octet_string
%xdefine _CBS_get_optional_asn1_uint64 _ %+ BORINGSSL_PREFIX %+ _CBS_get_optional_asn1_uint64
%xdefine _CBS_get_u16 _ %+ BORINGSSL_PREFIX %+ _CBS_get_u16
%xdefine _CBS_get_u16_length_prefixed _ %+ BORINGSSL_PREFIX %+ _CBS_get_u16_length_prefixed
%xdefine _CBS_get_u16le _ %+ BORINGSSL_PREFIX %+ _CBS_get_u16le
%xdefine _CBS_get_u24 _ %+ BORINGSSL_PREFIX %+ _CBS_get_u24
%xdefine _CBS_get_u24_length_prefixed _ %+ BORINGSSL_PREFIX %+ _CBS_get_u24_length_prefixed
%xdefine _CBS_get_u32 _ %+ BORINGSSL_PREFIX %+ _CBS_get_u32
%xdefine _CBS_get_u32le _ %+ BORINGSSL_PREFIX %+ _CBS_get_u32le
%xdefine _CBS_get_u64 _ %+ BORINGSSL_PREFIX %+ _CBS_get_u64
%xdefine _CBS_get_u64le _ %+ BORINGSSL_PREFIX %+ _CBS_get_u64le
%xdefine _CBS_get_u8 _ %+ BORINGSSL_PREFIX %+ _CBS_get_u8
%xdefine _CBS_get_u8_length_prefixed _ %+ BORINGSSL_PREFIX %+ _CBS_get_u8_length_prefixed
%xdefine _CBS_get_until_first _ %+ BORINGSSL_PREFIX %+ _CBS_get_until_first
%xdefine _CBS_init _ %+ BORINGSSL_PREFIX %+ _CBS_init
%xdefine _CBS_is_unsigned_asn1_integer _ %+ BORINGSSL_PREFIX %+ _CBS_is_unsigned_asn1_integer
%xdefine _CBS_is_valid_asn1_bitstring _ %+ BORINGSSL_PREFIX %+ _CBS_is_valid_asn1_bitstring
%xdefine _CBS_is_valid_asn1_integer _ %+ BORINGSSL_PREFIX %+ _CBS_is_valid_asn1_integer
%xdefine _CBS_len _ %+ BORINGSSL_PREFIX %+ _CBS_len
%xdefine _CBS_mem_equal _ %+ BORINGSSL_PREFIX %+ _CBS_mem_equal
%xdefine _CBS_peek_asn1_tag _ %+ BORINGSSL_PREFIX %+ _CBS_peek_asn1_tag
%xdefine _CBS_skip _ %+ BORINGSSL_PREFIX %+ _CBS_skip
%xdefine _CBS_stow _ %+ BORINGSSL_PREFIX %+ _CBS_stow
%xdefine _CBS_strdup _ %+ BORINGSSL_PREFIX %+ _CBS_strdup
%xdefine _CRYPTO_MUTEX_cleanup _ %+ BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_cleanup
%xdefine _CRYPTO_MUTEX_init _ %+ BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_init
%xdefine _CRYPTO_MUTEX_lock_read _ %+ BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_lock_read
%xdefine _CRYPTO_MUTEX_lock_write _ %+ BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_lock_write
%xdefine _CRYPTO_MUTEX_unlock_read _ %+ BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_unlock_read
%xdefine _CRYPTO_MUTEX_unlock_write _ %+ BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_unlock_write
%xdefine _CRYPTO_POLYVAL_finish _ %+ BORINGSSL_PREFIX %+ _CRYPTO_POLYVAL_finish
%xdefine _CRYPTO_POLYVAL_init _ %+ BORINGSSL_PREFIX %+ _CRYPTO_POLYVAL_init
%xdefine _CRYPTO_POLYVAL_update_blocks _ %+ BORINGSSL_PREFIX %+ _CRYPTO_POLYVAL_update_blocks
%xdefine _CRYPTO_STATIC_MUTEX_lock_read _ %+ BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_lock_read
%xdefine _CRYPTO_STATIC_MUTEX_lock_write _ %+ BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_lock_write
%xdefine _CRYPTO_STATIC_MUTEX_unlock_read _ %+ BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_unlock_read
%xdefine _CRYPTO_STATIC_MUTEX_unlock_write _ %+ BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_unlock_write
%xdefine _CRYPTO_THREADID_current _ %+ BORINGSSL_PREFIX %+ _CRYPTO_THREADID_current
%xdefine _CRYPTO_THREADID_set_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_THREADID_set_callback
%xdefine _CRYPTO_THREADID_set_numeric _ %+ BORINGSSL_PREFIX %+ _CRYPTO_THREADID_set_numeric
%xdefine _CRYPTO_THREADID_set_pointer _ %+ BORINGSSL_PREFIX %+ _CRYPTO_THREADID_set_pointer
%xdefine _CRYPTO_cbc128_decrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_cbc128_decrypt
%xdefine _CRYPTO_cbc128_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_cbc128_encrypt
%xdefine _CRYPTO_cfb128_1_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_cfb128_1_encrypt
%xdefine _CRYPTO_cfb128_8_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_cfb128_8_encrypt
%xdefine _CRYPTO_cfb128_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_cfb128_encrypt
%xdefine _CRYPTO_cleanup_all_ex_data _ %+ BORINGSSL_PREFIX %+ _CRYPTO_cleanup_all_ex_data
%xdefine _CRYPTO_ctr128_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_ctr128_encrypt
%xdefine _CRYPTO_ctr128_encrypt_ctr32 _ %+ BORINGSSL_PREFIX %+ _CRYPTO_ctr128_encrypt_ctr32
%xdefine _CRYPTO_fork_detect_ignore_madv_wipeonfork_for_testing _ %+ BORINGSSL_PREFIX %+ _CRYPTO_fork_detect_ignore_madv_wipeonfork_for_testing
%xdefine _CRYPTO_free _ %+ BORINGSSL_PREFIX %+ _CRYPTO_free
%xdefine _CRYPTO_free_ex_data _ %+ BORINGSSL_PREFIX %+ _CRYPTO_free_ex_data
%xdefine _CRYPTO_gcm128_aad _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_aad
%xdefine _CRYPTO_gcm128_decrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_decrypt
%xdefine _CRYPTO_gcm128_decrypt_ctr32 _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_decrypt_ctr32
%xdefine _CRYPTO_gcm128_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_encrypt
%xdefine _CRYPTO_gcm128_encrypt_ctr32 _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_encrypt_ctr32
%xdefine _CRYPTO_gcm128_finish _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_finish
%xdefine _CRYPTO_gcm128_init_key _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_init_key
%xdefine _CRYPTO_gcm128_setiv _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_setiv
%xdefine _CRYPTO_gcm128_tag _ %+ BORINGSSL_PREFIX %+ _CRYPTO_gcm128_tag
%xdefine _CRYPTO_get_dynlock_create_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_dynlock_create_callback
%xdefine _CRYPTO_get_dynlock_destroy_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_dynlock_destroy_callback
%xdefine _CRYPTO_get_dynlock_lock_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_dynlock_lock_callback
%xdefine _CRYPTO_get_ex_data _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_ex_data
%xdefine _CRYPTO_get_ex_new_index _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_ex_new_index
%xdefine _CRYPTO_get_fork_generation _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_fork_generation
%xdefine _CRYPTO_get_lock_name _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_lock_name
%xdefine _CRYPTO_get_locking_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_locking_callback
%xdefine _CRYPTO_get_thread_local _ %+ BORINGSSL_PREFIX %+ _CRYPTO_get_thread_local
%xdefine _CRYPTO_ghash_init _ %+ BORINGSSL_PREFIX %+ _CRYPTO_ghash_init
%xdefine _CRYPTO_has_asm _ %+ BORINGSSL_PREFIX %+ _CRYPTO_has_asm
%xdefine _CRYPTO_init_sysrand _ %+ BORINGSSL_PREFIX %+ _CRYPTO_init_sysrand
%xdefine _CRYPTO_is_confidential_build _ %+ BORINGSSL_PREFIX %+ _CRYPTO_is_confidential_build
%xdefine _CRYPTO_library_init _ %+ BORINGSSL_PREFIX %+ _CRYPTO_library_init
%xdefine _CRYPTO_malloc _ %+ BORINGSSL_PREFIX %+ _CRYPTO_malloc
%xdefine _CRYPTO_malloc_init _ %+ BORINGSSL_PREFIX %+ _CRYPTO_malloc_init
%xdefine _CRYPTO_memcmp _ %+ BORINGSSL_PREFIX %+ _CRYPTO_memcmp
%xdefine _CRYPTO_new_ex_data _ %+ BORINGSSL_PREFIX %+ _CRYPTO_new_ex_data
%xdefine _CRYPTO_num_locks _ %+ BORINGSSL_PREFIX %+ _CRYPTO_num_locks
%xdefine _CRYPTO_ofb128_encrypt _ %+ BORINGSSL_PREFIX %+ _CRYPTO_ofb128_encrypt
%xdefine _CRYPTO_once _ %+ BORINGSSL_PREFIX %+ _CRYPTO_once
%xdefine _CRYPTO_pre_sandbox_init _ %+ BORINGSSL_PREFIX %+ _CRYPTO_pre_sandbox_init
%xdefine _CRYPTO_rdrand _ %+ BORINGSSL_PREFIX %+ _CRYPTO_rdrand
%xdefine _CRYPTO_rdrand_multiple8_buf _ %+ BORINGSSL_PREFIX %+ _CRYPTO_rdrand_multiple8_buf
%xdefine _CRYPTO_realloc _ %+ BORINGSSL_PREFIX %+ _CRYPTO_realloc
%xdefine _CRYPTO_refcount_dec_and_test_zero _ %+ BORINGSSL_PREFIX %+ _CRYPTO_refcount_dec_and_test_zero
%xdefine _CRYPTO_refcount_inc _ %+ BORINGSSL_PREFIX %+ _CRYPTO_refcount_inc
%xdefine _CRYPTO_set_add_lock_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_add_lock_callback
%xdefine _CRYPTO_set_dynlock_create_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_dynlock_create_callback
%xdefine _CRYPTO_set_dynlock_destroy_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_dynlock_destroy_callback
%xdefine _CRYPTO_set_dynlock_lock_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_dynlock_lock_callback
%xdefine _CRYPTO_set_ex_data _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_ex_data
%xdefine _CRYPTO_set_id_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_id_callback
%xdefine _CRYPTO_set_locking_callback _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_locking_callback
%xdefine _CRYPTO_set_thread_local _ %+ BORINGSSL_PREFIX %+ _CRYPTO_set_thread_local
%xdefine _CRYPTO_sysrand _ %+ BORINGSSL_PREFIX %+ _CRYPTO_sysrand
%xdefine _CRYPTO_sysrand_for_seed _ %+ BORINGSSL_PREFIX %+ _CRYPTO_sysrand_for_seed
%xdefine _CRYPTO_sysrand_if_available _ %+ BORINGSSL_PREFIX %+ _CRYPTO_sysrand_if_available
%xdefine _CTR_DRBG_clear _ %+ BORINGSSL_PREFIX %+ _CTR_DRBG_clear
%xdefine _CTR_DRBG_generate _ %+ BORINGSSL_PREFIX %+ _CTR_DRBG_generate
%xdefine _CTR_DRBG_init _ %+ BORINGSSL_PREFIX %+ _CTR_DRBG_init
%xdefine _CTR_DRBG_reseed _ %+ BORINGSSL_PREFIX %+ _CTR_DRBG_reseed
%xdefine _ENGINE_load_builtin_engines _ %+ BORINGSSL_PREFIX %+ _ENGINE_load_builtin_engines
%xdefine _ENGINE_register_all_complete _ %+ BORINGSSL_PREFIX %+ _ENGINE_register_all_complete
%xdefine _ERR_SAVE_STATE_free _ %+ BORINGSSL_PREFIX %+ _ERR_SAVE_STATE_free
%xdefine _ERR_add_error_data _ %+ BORINGSSL_PREFIX %+ _ERR_add_error_data
%xdefine _ERR_add_error_dataf _ %+ BORINGSSL_PREFIX %+ _ERR_add_error_dataf
%xdefine _ERR_clear_error _ %+ BORINGSSL_PREFIX %+ _ERR_clear_error
%xdefine _ERR_clear_system_error _ %+ BORINGSSL_PREFIX %+ _ERR_clear_system_error
%xdefine _ERR_error_string _ %+ BORINGSSL_PREFIX %+ _ERR_error_string
%xdefine _ERR_error_string_n _ %+ BORINGSSL_PREFIX %+ _ERR_error_string_n
%xdefine _ERR_free_strings _ %+ BORINGSSL_PREFIX %+ _ERR_free_strings
%xdefine _ERR_func_error_string _ %+ BORINGSSL_PREFIX %+ _ERR_func_error_string
%xdefine _ERR_get_error _ %+ BORINGSSL_PREFIX %+ _ERR_get_error
%xdefine _ERR_get_error_line _ %+ BORINGSSL_PREFIX %+ _ERR_get_error_line
%xdefine _ERR_get_error_line_data _ %+ BORINGSSL_PREFIX %+ _ERR_get_error_line_data
%xdefine _ERR_get_next_error_library _ %+ BORINGSSL_PREFIX %+ _ERR_get_next_error_library
%xdefine _ERR_lib_error_string _ %+ BORINGSSL_PREFIX %+ _ERR_lib_error_string
%xdefine _ERR_load_BIO_strings _ %+ BORINGSSL_PREFIX %+ _ERR_load_BIO_strings
%xdefine _ERR_load_ERR_strings _ %+ BORINGSSL_PREFIX %+ _ERR_load_ERR_strings
%xdefine _ERR_load_RAND_strings _ %+ BORINGSSL_PREFIX %+ _ERR_load_RAND_strings
%xdefine _ERR_load_crypto_strings _ %+ BORINGSSL_PREFIX %+ _ERR_load_crypto_strings
%xdefine _ERR_peek_error _ %+ BORINGSSL_PREFIX %+ _ERR_peek_error
%xdefine _ERR_peek_error_line _ %+ BORINGSSL_PREFIX %+ _ERR_peek_error_line
%xdefine _ERR_peek_error_line_data _ %+ BORINGSSL_PREFIX %+ _ERR_peek_error_line_data
%xdefine _ERR_peek_last_error _ %+ BORINGSSL_PREFIX %+ _ERR_peek_last_error
%xdefine _ERR_peek_last_error_line _ %+ BORINGSSL_PREFIX %+ _ERR_peek_last_error_line
%xdefine _ERR_peek_last_error_line_data _ %+ BORINGSSL_PREFIX %+ _ERR_peek_last_error_line_data
%xdefine _ERR_pop_to_mark _ %+ BORINGSSL_PREFIX %+ _ERR_pop_to_mark
%xdefine _ERR_print_errors _ %+ BORINGSSL_PREFIX %+ _ERR_print_errors
%xdefine _ERR_print_errors_cb _ %+ BORINGSSL_PREFIX %+ _ERR_print_errors_cb
%xdefine _ERR_print_errors_fp _ %+ BORINGSSL_PREFIX %+ _ERR_print_errors_fp
%xdefine _ERR_put_error _ %+ BORINGSSL_PREFIX %+ _ERR_put_error
%xdefine _ERR_reason_error_string _ %+ BORINGSSL_PREFIX %+ _ERR_reason_error_string
%xdefine _ERR_remove_state _ %+ BORINGSSL_PREFIX %+ _ERR_remove_state
%xdefine _ERR_remove_thread_state _ %+ BORINGSSL_PREFIX %+ _ERR_remove_thread_state
%xdefine _ERR_restore_state _ %+ BORINGSSL_PREFIX %+ _ERR_restore_state
%xdefine _ERR_save_state _ %+ BORINGSSL_PREFIX %+ _ERR_save_state
%xdefine _ERR_set_error_data _ %+ BORINGSSL_PREFIX %+ _ERR_set_error_data
%xdefine _ERR_set_mark _ %+ BORINGSSL_PREFIX %+ _ERR_set_mark
%xdefine _EVP_CIPHER_CTX_block_size _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_block_size
%xdefine _EVP_CIPHER_CTX_cipher _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_cipher
%xdefine _EVP_CIPHER_CTX_cleanup _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_cleanup
%xdefine _EVP_CIPHER_CTX_copy _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_copy
%xdefine _EVP_CIPHER_CTX_ctrl _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_ctrl
%xdefine _EVP_CIPHER_CTX_encrypting _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_encrypting
%xdefine _EVP_CIPHER_CTX_flags _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_flags
%xdefine _EVP_CIPHER_CTX_free _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_free
%xdefine _EVP_CIPHER_CTX_get_app_data _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_get_app_data
%xdefine _EVP_CIPHER_CTX_init _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_init
%xdefine _EVP_CIPHER_CTX_iv_length _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_iv_length
%xdefine _EVP_CIPHER_CTX_key_length _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_key_length
%xdefine _EVP_CIPHER_CTX_mode _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_mode
%xdefine _EVP_CIPHER_CTX_new _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_new
%xdefine _EVP_CIPHER_CTX_nid _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_nid
%xdefine _EVP_CIPHER_CTX_reset _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_reset
%xdefine _EVP_CIPHER_CTX_set_app_data _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_app_data
%xdefine _EVP_CIPHER_CTX_set_flags _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_flags
%xdefine _EVP_CIPHER_CTX_set_key_length _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_key_length
%xdefine _EVP_CIPHER_CTX_set_padding _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_padding
%xdefine _EVP_CIPHER_block_size _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_block_size
%xdefine _EVP_CIPHER_flags _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_flags
%xdefine _EVP_CIPHER_iv_length _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_iv_length
%xdefine _EVP_CIPHER_key_length _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_key_length
%xdefine _EVP_CIPHER_mode _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_mode
%xdefine _EVP_CIPHER_nid _ %+ BORINGSSL_PREFIX %+ _EVP_CIPHER_nid
%xdefine _EVP_Cipher _ %+ BORINGSSL_PREFIX %+ _EVP_Cipher
%xdefine _EVP_CipherFinal _ %+ BORINGSSL_PREFIX %+ _EVP_CipherFinal
%xdefine _EVP_CipherFinal_ex _ %+ BORINGSSL_PREFIX %+ _EVP_CipherFinal_ex
%xdefine _EVP_CipherInit _ %+ BORINGSSL_PREFIX %+ _EVP_CipherInit
%xdefine _EVP_CipherInit_ex _ %+ BORINGSSL_PREFIX %+ _EVP_CipherInit_ex
%xdefine _EVP_CipherUpdate _ %+ BORINGSSL_PREFIX %+ _EVP_CipherUpdate
%xdefine _EVP_DecryptFinal _ %+ BORINGSSL_PREFIX %+ _EVP_DecryptFinal
%xdefine _EVP_DecryptFinal_ex _ %+ BORINGSSL_PREFIX %+ _EVP_DecryptFinal_ex
%xdefine _EVP_DecryptInit _ %+ BORINGSSL_PREFIX %+ _EVP_DecryptInit
%xdefine _EVP_DecryptInit_ex _ %+ BORINGSSL_PREFIX %+ _EVP_DecryptInit_ex
%xdefine _EVP_DecryptUpdate _ %+ BORINGSSL_PREFIX %+ _EVP_DecryptUpdate
%xdefine _EVP_EncryptFinal _ %+ BORINGSSL_PREFIX %+ _EVP_EncryptFinal
%xdefine _EVP_EncryptFinal_ex _ %+ BORINGSSL_PREFIX %+ _EVP_EncryptFinal_ex
%xdefine _EVP_EncryptInit _ %+ BORINGSSL_PREFIX %+ _EVP_EncryptInit
%xdefine _EVP_EncryptInit_ex _ %+ BORINGSSL_PREFIX %+ _EVP_EncryptInit_ex
%xdefine _EVP_EncryptUpdate _ %+ BORINGSSL_PREFIX %+ _EVP_EncryptUpdate
%xdefine _EVP_add_cipher_alias _ %+ BORINGSSL_PREFIX %+ _EVP_add_cipher_alias
%xdefine _EVP_aead_aes_128_gcm _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm
%xdefine _EVP_aead_aes_128_gcm_randnonce _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm_randnonce
%xdefine _EVP_aead_aes_128_gcm_tls12 _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm_tls12
%xdefine _EVP_aead_aes_128_gcm_tls13 _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm_tls13
%xdefine _EVP_aead_aes_192_gcm _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_192_gcm
%xdefine _EVP_aead_aes_256_gcm _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm
%xdefine _EVP_aead_aes_256_gcm_randnonce _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm_randnonce
%xdefine _EVP_aead_aes_256_gcm_tls12 _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm_tls12
%xdefine _EVP_aead_aes_256_gcm_tls13 _ %+ BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm_tls13
%xdefine _EVP_aes_128_cbc _ %+ BORINGSSL_PREFIX %+ _EVP_aes_128_cbc
%xdefine _EVP_aes_128_ctr _ %+ BORINGSSL_PREFIX %+ _EVP_aes_128_ctr
%xdefine _EVP_aes_128_ecb _ %+ BORINGSSL_PREFIX %+ _EVP_aes_128_ecb
%xdefine _EVP_aes_128_gcm _ %+ BORINGSSL_PREFIX %+ _EVP_aes_128_gcm
%xdefine _EVP_aes_128_ofb _ %+ BORINGSSL_PREFIX %+ _EVP_aes_128_ofb
%xdefine _EVP_aes_192_cbc _ %+ BORINGSSL_PREFIX %+ _EVP_aes_192_cbc
%xdefine _EVP_aes_192_ctr _ %+ BORINGSSL_PREFIX %+ _EVP_aes_192_ctr
%xdefine _EVP_aes_192_ecb _ %+ BORINGSSL_PREFIX %+ _EVP_aes_192_ecb
%xdefine _EVP_aes_192_gcm _ %+ BORINGSSL_PREFIX %+ _EVP_aes_192_gcm
%xdefine _EVP_aes_192_ofb _ %+ BORINGSSL_PREFIX %+ _EVP_aes_192_ofb
%xdefine _EVP_aes_256_cbc _ %+ BORINGSSL_PREFIX %+ _EVP_aes_256_cbc
%xdefine _EVP_aes_256_ctr _ %+ BORINGSSL_PREFIX %+ _EVP_aes_256_ctr
%xdefine _EVP_aes_256_ecb _ %+ BORINGSSL_PREFIX %+ _EVP_aes_256_ecb
%xdefine _EVP_aes_256_gcm _ %+ BORINGSSL_PREFIX %+ _EVP_aes_256_gcm
%xdefine _EVP_aes_256_ofb _ %+ BORINGSSL_PREFIX %+ _EVP_aes_256_ofb
%xdefine _EVP_has_aes_hardware _ %+ BORINGSSL_PREFIX %+ _EVP_has_aes_hardware
%xdefine _OPENSSL_cleanse _ %+ BORINGSSL_PREFIX %+ _OPENSSL_cleanse
%xdefine _OPENSSL_cleanup _ %+ BORINGSSL_PREFIX %+ _OPENSSL_cleanup
%xdefine _OPENSSL_clear_free _ %+ BORINGSSL_PREFIX %+ _OPENSSL_clear_free
%xdefine _OPENSSL_cpuid_setup _ %+ BORINGSSL_PREFIX %+ _OPENSSL_cpuid_setup
%xdefine _OPENSSL_free _ %+ BORINGSSL_PREFIX %+ _OPENSSL_free
%xdefine _OPENSSL_hash32 _ %+ BORINGSSL_PREFIX %+ _OPENSSL_hash32
%xdefine _OPENSSL_ia32cap_P _ %+ BORINGSSL_PREFIX %+ _OPENSSL_ia32cap_P
%xdefine _OPENSSL_init_crypto _ %+ BORINGSSL_PREFIX %+ _OPENSSL_init_crypto
%xdefine _OPENSSL_load_builtin_modules _ %+ BORINGSSL_PREFIX %+ _OPENSSL_load_builtin_modules
%xdefine _OPENSSL_malloc _ %+ BORINGSSL_PREFIX %+ _OPENSSL_malloc
%xdefine _OPENSSL_malloc_init _ %+ BORINGSSL_PREFIX %+ _OPENSSL_malloc_init
%xdefine _OPENSSL_memdup _ %+ BORINGSSL_PREFIX %+ _OPENSSL_memdup
%xdefine _OPENSSL_realloc _ %+ BORINGSSL_PREFIX %+ _OPENSSL_realloc
%xdefine _OPENSSL_strcasecmp _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strcasecmp
%xdefine _OPENSSL_strdup _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strdup
%xdefine _OPENSSL_strhash _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strhash
%xdefine _OPENSSL_strlcat _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strlcat
%xdefine _OPENSSL_strlcpy _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strlcpy
%xdefine _OPENSSL_strncasecmp _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strncasecmp
%xdefine _OPENSSL_strndup _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strndup
%xdefine _OPENSSL_strnlen _ %+ BORINGSSL_PREFIX %+ _OPENSSL_strnlen
%xdefine _OPENSSL_tolower _ %+ BORINGSSL_PREFIX %+ _OPENSSL_tolower
%xdefine _OpenSSL_version _ %+ BORINGSSL_PREFIX %+ _OpenSSL_version
%xdefine _OpenSSL_version_num _ %+ BORINGSSL_PREFIX %+ _OpenSSL_version_num
%xdefine _RAND_OpenSSL _ %+ BORINGSSL_PREFIX %+ _RAND_OpenSSL
%xdefine _RAND_SSLeay _ %+ BORINGSSL_PREFIX %+ _RAND_SSLeay
%xdefine _RAND_add _ %+ BORINGSSL_PREFIX %+ _RAND_add
%xdefine _RAND_bytes _ %+ BORINGSSL_PREFIX %+ _RAND_bytes
%xdefine _RAND_bytes_with_additional_data _ %+ BORINGSSL_PREFIX %+ _RAND_bytes_with_additional_data
%xdefine _RAND_cleanup _ %+ BORINGSSL_PREFIX %+ _RAND_cleanup
%xdefine _RAND_egd _ %+ BORINGSSL_PREFIX %+ _RAND_egd
%xdefine _RAND_enable_fork_unsafe_buffering _ %+ BORINGSSL_PREFIX %+ _RAND_enable_fork_unsafe_buffering
%xdefine _RAND_file_name _ %+ BORINGSSL_PREFIX %+ _RAND_file_name
%xdefine _RAND_get_rand_method _ %+ BORINGSSL_PREFIX %+ _RAND_get_rand_method
%xdefine _RAND_load_file _ %+ BORINGSSL_PREFIX %+ _RAND_load_file
%xdefine _RAND_poll _ %+ BORINGSSL_PREFIX %+ _RAND_poll
%xdefine _RAND_pseudo_bytes _ %+ BORINGSSL_PREFIX %+ _RAND_pseudo_bytes
%xdefine _RAND_seed _ %+ BORINGSSL_PREFIX %+ _RAND_seed
%xdefine _RAND_set_rand_method _ %+ BORINGSSL_PREFIX %+ _RAND_set_rand_method
%xdefine _RAND_status _ %+ BORINGSSL_PREFIX %+ _RAND_status
%xdefine _RSAZ_1024_mod_exp_avx2 _ %+ BORINGSSL_PREFIX %+ _RSAZ_1024_mod_exp_avx2
%xdefine _SSLeay _ %+ BORINGSSL_PREFIX %+ _SSLeay
%xdefine _SSLeay_version _ %+ BORINGSSL_PREFIX %+ _SSLeay_version
%xdefine ___clang_at_available_requires_core_foundation_framework _ %+ BORINGSSL_PREFIX %+ ___clang_at_available_requires_core_foundation_framework
%xdefine _aes_ctr_set_key _ %+ BORINGSSL_PREFIX %+ _aes_ctr_set_key
%xdefine _aes_hw_cbc_encrypt _ %+ BORINGSSL_PREFIX %+ _aes_hw_cbc_encrypt
%xdefine _aes_hw_ctr32_encrypt_blocks _ %+ BORINGSSL_PREFIX %+ _aes_hw_ctr32_encrypt_blocks
%xdefine _aes_hw_decrypt _ %+ BORINGSSL_PREFIX %+ _aes_hw_decrypt
%xdefine _aes_hw_ecb_encrypt _ %+ BORINGSSL_PREFIX %+ _aes_hw_ecb_encrypt
%xdefine _aes_hw_encrypt _ %+ BORINGSSL_PREFIX %+ _aes_hw_encrypt
%xdefine _aes_hw_set_decrypt_key _ %+ BORINGSSL_PREFIX %+ _aes_hw_set_decrypt_key
%xdefine _aes_hw_set_encrypt_key _ %+ BORINGSSL_PREFIX %+ _aes_hw_set_encrypt_key
%xdefine _aes_nohw_cbc_encrypt _ %+ BORINGSSL_PREFIX %+ _aes_nohw_cbc_encrypt
%xdefine _aes_nohw_ctr32_encrypt_blocks _ %+ BORINGSSL_PREFIX %+ _aes_nohw_ctr32_encrypt_blocks
%xdefine _aes_nohw_decrypt _ %+ BORINGSSL_PREFIX %+ _aes_nohw_decrypt
%xdefine _aes_nohw_encrypt _ %+ BORINGSSL_PREFIX %+ _aes_nohw_encrypt
%xdefine _aes_nohw_set_decrypt_key _ %+ BORINGSSL_PREFIX %+ _aes_nohw_set_decrypt_key
%xdefine _aes_nohw_set_encrypt_key _ %+ BORINGSSL_PREFIX %+ _aes_nohw_set_encrypt_key
%xdefine _aesni_gcm_decrypt _ %+ BORINGSSL_PREFIX %+ _aesni_gcm_decrypt
%xdefine _aesni_gcm_encrypt _ %+ BORINGSSL_PREFIX %+ _aesni_gcm_encrypt
%xdefine _beeu_mod_inverse_vartime _ %+ BORINGSSL_PREFIX %+ _beeu_mod_inverse_vartime
%xdefine _bn_abs_sub_consttime _ %+ BORINGSSL_PREFIX %+ _bn_abs_sub_consttime
%xdefine _bn_add_words _ %+ BORINGSSL_PREFIX %+ _bn_add_words
%xdefine _bn_copy_words _ %+ BORINGSSL_PREFIX %+ _bn_copy_words
%xdefine _bn_div_consttime _ %+ BORINGSSL_PREFIX %+ _bn_div_consttime
%xdefine _bn_expand _ %+ BORINGSSL_PREFIX %+ _bn_expand
%xdefine _bn_fits_in_words _ %+ BORINGSSL_PREFIX %+ _bn_fits_in_words
%xdefine _bn_from_montgomery _ %+ BORINGSSL_PREFIX %+ _bn_from_montgomery
%xdefine _bn_from_montgomery_small _ %+ BORINGSSL_PREFIX %+ _bn_from_montgomery_small
%xdefine _bn_gather5 _ %+ BORINGSSL_PREFIX %+ _bn_gather5
%xdefine _bn_in_range_words _ %+ BORINGSSL_PREFIX %+ _bn_in_range_words
%xdefine _bn_is_bit_set_words _ %+ BORINGSSL_PREFIX %+ _bn_is_bit_set_words
%xdefine _bn_is_relatively_prime _ %+ BORINGSSL_PREFIX %+ _bn_is_relatively_prime
%xdefine _bn_jacobi _ %+ BORINGSSL_PREFIX %+ _bn_jacobi
%xdefine _bn_lcm_consttime _ %+ BORINGSSL_PREFIX %+ _bn_lcm_consttime
%xdefine _bn_less_than_montgomery_R _ %+ BORINGSSL_PREFIX %+ _bn_less_than_montgomery_R
%xdefine _bn_less_than_words _ %+ BORINGSSL_PREFIX %+ _bn_less_than_words
%xdefine _bn_miller_rabin_init _ %+ BORINGSSL_PREFIX %+ _bn_miller_rabin_init
%xdefine _bn_miller_rabin_iteration _ %+ BORINGSSL_PREFIX %+ _bn_miller_rabin_iteration
%xdefine _bn_minimal_width _ %+ BORINGSSL_PREFIX %+ _bn_minimal_width
%xdefine _bn_mod_add_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_add_consttime
%xdefine _bn_mod_add_words _ %+ BORINGSSL_PREFIX %+ _bn_mod_add_words
%xdefine _bn_mod_exp_base_2_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_exp_base_2_consttime
%xdefine _bn_mod_exp_mont_small _ %+ BORINGSSL_PREFIX %+ _bn_mod_exp_mont_small
%xdefine _bn_mod_inverse0_prime_mont_small _ %+ BORINGSSL_PREFIX %+ _bn_mod_inverse0_prime_mont_small
%xdefine _bn_mod_inverse_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_inverse_consttime
%xdefine _bn_mod_inverse_prime _ %+ BORINGSSL_PREFIX %+ _bn_mod_inverse_prime
%xdefine _bn_mod_inverse_secret_prime _ %+ BORINGSSL_PREFIX %+ _bn_mod_inverse_secret_prime
%xdefine _bn_mod_lshift1_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_lshift1_consttime
%xdefine _bn_mod_lshift_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_lshift_consttime
%xdefine _bn_mod_mul_montgomery_small _ %+ BORINGSSL_PREFIX %+ _bn_mod_mul_montgomery_small
%xdefine _bn_mod_sub_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_sub_consttime
%xdefine _bn_mod_sub_words _ %+ BORINGSSL_PREFIX %+ _bn_mod_sub_words
%xdefine _bn_mod_u16_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mod_u16_consttime
%xdefine _bn_mont_n0 _ %+ BORINGSSL_PREFIX %+ _bn_mont_n0
%xdefine _bn_mul_add_words _ %+ BORINGSSL_PREFIX %+ _bn_mul_add_words
%xdefine _bn_mul_comba4 _ %+ BORINGSSL_PREFIX %+ _bn_mul_comba4
%xdefine _bn_mul_comba8 _ %+ BORINGSSL_PREFIX %+ _bn_mul_comba8
%xdefine _bn_mul_consttime _ %+ BORINGSSL_PREFIX %+ _bn_mul_consttime
%xdefine _bn_mul_mont _ %+ BORINGSSL_PREFIX %+ _bn_mul_mont
%xdefine _bn_mul_mont_gather5 _ %+ BORINGSSL_PREFIX %+ _bn_mul_mont_gather5
%xdefine _bn_mul_small _ %+ BORINGSSL_PREFIX %+ _bn_mul_small
%xdefine _bn_mul_words _ %+ BORINGSSL_PREFIX %+ _bn_mul_words
%xdefine _bn_odd_number_is_obviously_composite _ %+ BORINGSSL_PREFIX %+ _bn_odd_number_is_obviously_composite
%xdefine _bn_one_to_montgomery _ %+ BORINGSSL_PREFIX %+ _bn_one_to_montgomery
%xdefine _bn_power5 _ %+ BORINGSSL_PREFIX %+ _bn_power5
%xdefine _bn_rand_range_words _ %+ BORINGSSL_PREFIX %+ _bn_rand_range_words
%xdefine _bn_rand_secret_range _ %+ BORINGSSL_PREFIX %+ _bn_rand_secret_range
%xdefine _bn_reduce_once _ %+ BORINGSSL_PREFIX %+ _bn_reduce_once
%xdefine _bn_reduce_once_in_place _ %+ BORINGSSL_PREFIX %+ _bn_reduce_once_in_place
%xdefine _bn_resize_words _ %+ BORINGSSL_PREFIX %+ _bn_resize_words
%xdefine _bn_rshift1_words _ %+ BORINGSSL_PREFIX %+ _bn_rshift1_words
%xdefine _bn_rshift_secret_shift _ %+ BORINGSSL_PREFIX %+ _bn_rshift_secret_shift
%xdefine _bn_rshift_words _ %+ BORINGSSL_PREFIX %+ _bn_rshift_words
%xdefine _bn_scatter5 _ %+ BORINGSSL_PREFIX %+ _bn_scatter5
%xdefine _bn_select_words _ %+ BORINGSSL_PREFIX %+ _bn_select_words
%xdefine _bn_set_minimal_width _ %+ BORINGSSL_PREFIX %+ _bn_set_minimal_width
%xdefine _bn_set_static_words _ %+ BORINGSSL_PREFIX %+ _bn_set_static_words
%xdefine _bn_set_words _ %+ BORINGSSL_PREFIX %+ _bn_set_words
%xdefine _bn_sqr8x_internal _ %+ BORINGSSL_PREFIX %+ _bn_sqr8x_internal
%xdefine _bn_sqr_comba4 _ %+ BORINGSSL_PREFIX %+ _bn_sqr_comba4
%xdefine _bn_sqr_comba8 _ %+ BORINGSSL_PREFIX %+ _bn_sqr_comba8
%xdefine _bn_sqr_consttime _ %+ BORINGSSL_PREFIX %+ _bn_sqr_consttime
%xdefine _bn_sqr_small _ %+ BORINGSSL_PREFIX %+ _bn_sqr_small
%xdefine _bn_sqr_words _ %+ BORINGSSL_PREFIX %+ _bn_sqr_words
%xdefine _bn_sqrx8x_internal _ %+ BORINGSSL_PREFIX %+ _bn_sqrx8x_internal
%xdefine _bn_sub_words _ %+ BORINGSSL_PREFIX %+ _bn_sub_words
%xdefine _bn_to_montgomery_small _ %+ BORINGSSL_PREFIX %+ _bn_to_montgomery_small
%xdefine _bn_uadd_consttime _ %+ BORINGSSL_PREFIX %+ _bn_uadd_consttime
%xdefine _bn_usub_consttime _ %+ BORINGSSL_PREFIX %+ _bn_usub_consttime
%xdefine _bn_wexpand _ %+ BORINGSSL_PREFIX %+ _bn_wexpand
%xdefine _cbb_add_latin1 _ %+ BORINGSSL_PREFIX %+ _cbb_add_latin1
%xdefine _cbb_add_ucs2_be _ %+ BORINGSSL_PREFIX %+ _cbb_add_ucs2_be
%xdefine _cbb_add_utf32_be _ %+ BORINGSSL_PREFIX %+ _cbb_add_utf32_be
%xdefine _cbb_add_utf8 _ %+ BORINGSSL_PREFIX %+ _cbb_add_utf8
%xdefine _cbb_get_utf8_len _ %+ BORINGSSL_PREFIX %+ _cbb_get_utf8_len
%xdefine _cbs_get_latin1 _ %+ BORINGSSL_PREFIX %+ _cbs_get_latin1
%xdefine _cbs_get_ucs2_be _ %+ BORINGSSL_PREFIX %+ _cbs_get_ucs2_be
%xdefine _cbs_get_utf32_be _ %+ BORINGSSL_PREFIX %+ _cbs_get_utf32_be
%xdefine _cbs_get_utf8 _ %+ BORINGSSL_PREFIX %+ _cbs_get_utf8
%xdefine _crypto_gcm_clmul_enabled _ %+ BORINGSSL_PREFIX %+ _crypto_gcm_clmul_enabled
%xdefine _ecp_nistz256_avx2_select_w7 _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_avx2_select_w7
%xdefine _ecp_nistz256_mul_mont _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_mul_mont
%xdefine _ecp_nistz256_neg _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_neg
%xdefine _ecp_nistz256_ord_mul_mont _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_ord_mul_mont
%xdefine _ecp_nistz256_ord_sqr_mont _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_ord_sqr_mont
%xdefine _ecp_nistz256_point_add _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_point_add
%xdefine _ecp_nistz256_point_add_affine _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_point_add_affine
%xdefine _ecp_nistz256_point_double _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_point_double
%xdefine _ecp_nistz256_select_w5 _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_select_w5
%xdefine _ecp_nistz256_select_w7 _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_select_w7
%xdefine _ecp_nistz256_sqr_mont _ %+ BORINGSSL_PREFIX %+ _ecp_nistz256_sqr_mont
%xdefine _gcm_ghash_avx _ %+ BORINGSSL_PREFIX %+ _gcm_ghash_avx
%xdefine _gcm_ghash_clmul _ %+ BORINGSSL_PREFIX %+ _gcm_ghash_clmul
%xdefine _gcm_ghash_nohw _ %+ BORINGSSL_PREFIX %+ _gcm_ghash_nohw
%xdefine _gcm_ghash_ssse3 _ %+ BORINGSSL_PREFIX %+ _gcm_ghash_ssse3
%xdefine _gcm_gmult_avx _ %+ BORINGSSL_PREFIX %+ _gcm_gmult_avx
%xdefine _gcm_gmult_clmul _ %+ BORINGSSL_PREFIX %+ _gcm_gmult_clmul
%xdefine _gcm_gmult_nohw _ %+ BORINGSSL_PREFIX %+ _gcm_gmult_nohw
%xdefine _gcm_gmult_ssse3 _ %+ BORINGSSL_PREFIX %+ _gcm_gmult_ssse3
%xdefine _gcm_init_avx _ %+ BORINGSSL_PREFIX %+ _gcm_init_avx
%xdefine _gcm_init_clmul _ %+ BORINGSSL_PREFIX %+ _gcm_init_clmul
%xdefine _gcm_init_nohw _ %+ BORINGSSL_PREFIX %+ _gcm_init_nohw
%xdefine _gcm_init_ssse3 _ %+ BORINGSSL_PREFIX %+ _gcm_init_ssse3
%xdefine _kOpenSSLReasonStringData _ %+ BORINGSSL_PREFIX %+ _kOpenSSLReasonStringData
%xdefine _kOpenSSLReasonValues _ %+ BORINGSSL_PREFIX %+ _kOpenSSLReasonValues
%xdefine _kOpenSSLReasonValuesLen _ %+ BORINGSSL_PREFIX %+ _kOpenSSLReasonValuesLen
%xdefine _md5_block_asm_data_order _ %+ BORINGSSL_PREFIX %+ _md5_block_asm_data_order
%xdefine _rand_fork_unsafe_buffering_enabled _ %+ BORINGSSL_PREFIX %+ _rand_fork_unsafe_buffering_enabled
%xdefine _rsaz_1024_gather5_avx2 _ %+ BORINGSSL_PREFIX %+ _rsaz_1024_gather5_avx2
%xdefine _rsaz_1024_mul_avx2 _ %+ BORINGSSL_PREFIX %+ _rsaz_1024_mul_avx2
%xdefine _rsaz_1024_norm2red_avx2 _ %+ BORINGSSL_PREFIX %+ _rsaz_1024_norm2red_avx2
%xdefine _rsaz_1024_red2norm_avx2 _ %+ BORINGSSL_PREFIX %+ _rsaz_1024_red2norm_avx2
%xdefine _rsaz_1024_scatter5_avx2 _ %+ BORINGSSL_PREFIX %+ _rsaz_1024_scatter5_avx2
%xdefine _rsaz_1024_sqr_avx2 _ %+ BORINGSSL_PREFIX %+ _rsaz_1024_sqr_avx2
%xdefine _sha1_block_data_order _ %+ BORINGSSL_PREFIX %+ _sha1_block_data_order
%xdefine _sha256_block_data_order _ %+ BORINGSSL_PREFIX %+ _sha256_block_data_order
%xdefine _sha512_block_data_order _ %+ BORINGSSL_PREFIX %+ _sha512_block_data_order
%xdefine _sk_deep_copy _ %+ BORINGSSL_PREFIX %+ _sk_deep_copy
%xdefine _sk_delete _ %+ BORINGSSL_PREFIX %+ _sk_delete
%xdefine _sk_delete_ptr _ %+ BORINGSSL_PREFIX %+ _sk_delete_ptr
%xdefine _sk_dup _ %+ BORINGSSL_PREFIX %+ _sk_dup
%xdefine _sk_find _ %+ BORINGSSL_PREFIX %+ _sk_find
%xdefine _sk_free _ %+ BORINGSSL_PREFIX %+ _sk_free
%xdefine _sk_insert _ %+ BORINGSSL_PREFIX %+ _sk_insert
%xdefine _sk_is_sorted _ %+ BORINGSSL_PREFIX %+ _sk_is_sorted
%xdefine _sk_new _ %+ BORINGSSL_PREFIX %+ _sk_new
%xdefine _sk_new_null _ %+ BORINGSSL_PREFIX %+ _sk_new_null
%xdefine _sk_num _ %+ BORINGSSL_PREFIX %+ _sk_num
%xdefine _sk_pop _ %+ BORINGSSL_PREFIX %+ _sk_pop
%xdefine _sk_pop_free _ %+ BORINGSSL_PREFIX %+ _sk_pop_free
%xdefine _sk_pop_free_ex _ %+ BORINGSSL_PREFIX %+ _sk_pop_free_ex
%xdefine _sk_push _ %+ BORINGSSL_PREFIX %+ _sk_push
%xdefine _sk_set _ %+ BORINGSSL_PREFIX %+ _sk_set
%xdefine _sk_set_cmp_func _ %+ BORINGSSL_PREFIX %+ _sk_set_cmp_func
%xdefine _sk_shift _ %+ BORINGSSL_PREFIX %+ _sk_shift
%xdefine _sk_sort _ %+ BORINGSSL_PREFIX %+ _sk_sort
%xdefine _sk_value _ %+ BORINGSSL_PREFIX %+ _sk_value
%xdefine _sk_zero _ %+ BORINGSSL_PREFIX %+ _sk_zero
%xdefine _vpaes_cbc_encrypt _ %+ BORINGSSL_PREFIX %+ _vpaes_cbc_encrypt
%xdefine _vpaes_ctr32_encrypt_blocks _ %+ BORINGSSL_PREFIX %+ _vpaes_ctr32_encrypt_blocks
%xdefine _vpaes_decrypt _ %+ BORINGSSL_PREFIX %+ _vpaes_decrypt
%xdefine _vpaes_encrypt _ %+ BORINGSSL_PREFIX %+ _vpaes_encrypt
%xdefine _vpaes_set_decrypt_key _ %+ BORINGSSL_PREFIX %+ _vpaes_set_decrypt_key
%xdefine _vpaes_set_encrypt_key _ %+ BORINGSSL_PREFIX %+ _vpaes_set_encrypt_key
%else
%xdefine AES_cbc_encrypt BORINGSSL_PREFIX %+ _AES_cbc_encrypt
%xdefine AES_cfb128_encrypt BORINGSSL_PREFIX %+ _AES_cfb128_encrypt
%xdefine AES_ctr128_encrypt BORINGSSL_PREFIX %+ _AES_ctr128_encrypt
%xdefine AES_decrypt BORINGSSL_PREFIX %+ _AES_decrypt
%xdefine AES_ecb_encrypt BORINGSSL_PREFIX %+ _AES_ecb_encrypt
%xdefine AES_encrypt BORINGSSL_PREFIX %+ _AES_encrypt
%xdefine AES_ofb128_encrypt BORINGSSL_PREFIX %+ _AES_ofb128_encrypt
%xdefine AES_set_decrypt_key BORINGSSL_PREFIX %+ _AES_set_decrypt_key
%xdefine AES_set_encrypt_key BORINGSSL_PREFIX %+ _AES_set_encrypt_key
%xdefine AES_unwrap_key BORINGSSL_PREFIX %+ _AES_unwrap_key
%xdefine AES_unwrap_key_padded BORINGSSL_PREFIX %+ _AES_unwrap_key_padded
%xdefine AES_wrap_key BORINGSSL_PREFIX %+ _AES_wrap_key
%xdefine AES_wrap_key_padded BORINGSSL_PREFIX %+ _AES_wrap_key_padded
%xdefine BIO_append_filename BORINGSSL_PREFIX %+ _BIO_append_filename
%xdefine BIO_callback_ctrl BORINGSSL_PREFIX %+ _BIO_callback_ctrl
%xdefine BIO_clear_flags BORINGSSL_PREFIX %+ _BIO_clear_flags
%xdefine BIO_clear_retry_flags BORINGSSL_PREFIX %+ _BIO_clear_retry_flags
%xdefine BIO_copy_next_retry BORINGSSL_PREFIX %+ _BIO_copy_next_retry
%xdefine BIO_ctrl BORINGSSL_PREFIX %+ _BIO_ctrl
%xdefine BIO_ctrl_pending BORINGSSL_PREFIX %+ _BIO_ctrl_pending
%xdefine BIO_eof BORINGSSL_PREFIX %+ _BIO_eof
%xdefine BIO_find_type BORINGSSL_PREFIX %+ _BIO_find_type
%xdefine BIO_flush BORINGSSL_PREFIX %+ _BIO_flush
%xdefine BIO_free BORINGSSL_PREFIX %+ _BIO_free
%xdefine BIO_free_all BORINGSSL_PREFIX %+ _BIO_free_all
%xdefine BIO_get_data BORINGSSL_PREFIX %+ _BIO_get_data
%xdefine BIO_get_fp BORINGSSL_PREFIX %+ _BIO_get_fp
%xdefine BIO_get_init BORINGSSL_PREFIX %+ _BIO_get_init
%xdefine BIO_get_new_index BORINGSSL_PREFIX %+ _BIO_get_new_index
%xdefine BIO_get_retry_flags BORINGSSL_PREFIX %+ _BIO_get_retry_flags
%xdefine BIO_get_retry_reason BORINGSSL_PREFIX %+ _BIO_get_retry_reason
%xdefine BIO_get_shutdown BORINGSSL_PREFIX %+ _BIO_get_shutdown
%xdefine BIO_gets BORINGSSL_PREFIX %+ _BIO_gets
%xdefine BIO_indent BORINGSSL_PREFIX %+ _BIO_indent
%xdefine BIO_int_ctrl BORINGSSL_PREFIX %+ _BIO_int_ctrl
%xdefine BIO_meth_free BORINGSSL_PREFIX %+ _BIO_meth_free
%xdefine BIO_meth_new BORINGSSL_PREFIX %+ _BIO_meth_new
%xdefine BIO_meth_set_create BORINGSSL_PREFIX %+ _BIO_meth_set_create
%xdefine BIO_meth_set_ctrl BORINGSSL_PREFIX %+ _BIO_meth_set_ctrl
%xdefine BIO_meth_set_destroy BORINGSSL_PREFIX %+ _BIO_meth_set_destroy
%xdefine BIO_meth_set_gets BORINGSSL_PREFIX %+ _BIO_meth_set_gets
%xdefine BIO_meth_set_puts BORINGSSL_PREFIX %+ _BIO_meth_set_puts
%xdefine BIO_meth_set_read BORINGSSL_PREFIX %+ _BIO_meth_set_read
%xdefine BIO_meth_set_write BORINGSSL_PREFIX %+ _BIO_meth_set_write
%xdefine BIO_method_type BORINGSSL_PREFIX %+ _BIO_method_type
%xdefine BIO_new BORINGSSL_PREFIX %+ _BIO_new
%xdefine BIO_new_file BORINGSSL_PREFIX %+ _BIO_new_file
%xdefine BIO_new_fp BORINGSSL_PREFIX %+ _BIO_new_fp
%xdefine BIO_next BORINGSSL_PREFIX %+ _BIO_next
%xdefine BIO_number_read BORINGSSL_PREFIX %+ _BIO_number_read
%xdefine BIO_number_written BORINGSSL_PREFIX %+ _BIO_number_written
%xdefine BIO_pending BORINGSSL_PREFIX %+ _BIO_pending
%xdefine BIO_pop BORINGSSL_PREFIX %+ _BIO_pop
%xdefine BIO_ptr_ctrl BORINGSSL_PREFIX %+ _BIO_ptr_ctrl
%xdefine BIO_push BORINGSSL_PREFIX %+ _BIO_push
%xdefine BIO_puts BORINGSSL_PREFIX %+ _BIO_puts
%xdefine BIO_read BORINGSSL_PREFIX %+ _BIO_read
%xdefine BIO_read_asn1 BORINGSSL_PREFIX %+ _BIO_read_asn1
%xdefine BIO_read_filename BORINGSSL_PREFIX %+ _BIO_read_filename
%xdefine BIO_reset BORINGSSL_PREFIX %+ _BIO_reset
%xdefine BIO_rw_filename BORINGSSL_PREFIX %+ _BIO_rw_filename
%xdefine BIO_s_file BORINGSSL_PREFIX %+ _BIO_s_file
%xdefine BIO_seek BORINGSSL_PREFIX %+ _BIO_seek
%xdefine BIO_set_close BORINGSSL_PREFIX %+ _BIO_set_close
%xdefine BIO_set_data BORINGSSL_PREFIX %+ _BIO_set_data
%xdefine BIO_set_flags BORINGSSL_PREFIX %+ _BIO_set_flags
%xdefine BIO_set_fp BORINGSSL_PREFIX %+ _BIO_set_fp
%xdefine BIO_set_init BORINGSSL_PREFIX %+ _BIO_set_init
%xdefine BIO_set_retry_read BORINGSSL_PREFIX %+ _BIO_set_retry_read
%xdefine BIO_set_retry_reason BORINGSSL_PREFIX %+ _BIO_set_retry_reason
%xdefine BIO_set_retry_special BORINGSSL_PREFIX %+ _BIO_set_retry_special
%xdefine BIO_set_retry_write BORINGSSL_PREFIX %+ _BIO_set_retry_write
%xdefine BIO_set_shutdown BORINGSSL_PREFIX %+ _BIO_set_shutdown
%xdefine BIO_set_write_buffer_size BORINGSSL_PREFIX %+ _BIO_set_write_buffer_size
%xdefine BIO_should_io_special BORINGSSL_PREFIX %+ _BIO_should_io_special
%xdefine BIO_should_read BORINGSSL_PREFIX %+ _BIO_should_read
%xdefine BIO_should_retry BORINGSSL_PREFIX %+ _BIO_should_retry
%xdefine BIO_should_write BORINGSSL_PREFIX %+ _BIO_should_write
%xdefine BIO_snprintf BORINGSSL_PREFIX %+ _BIO_snprintf
%xdefine BIO_tell BORINGSSL_PREFIX %+ _BIO_tell
%xdefine BIO_test_flags BORINGSSL_PREFIX %+ _BIO_test_flags
%xdefine BIO_up_ref BORINGSSL_PREFIX %+ _BIO_up_ref
%xdefine BIO_vfree BORINGSSL_PREFIX %+ _BIO_vfree
%xdefine BIO_vsnprintf BORINGSSL_PREFIX %+ _BIO_vsnprintf
%xdefine BIO_wpending BORINGSSL_PREFIX %+ _BIO_wpending
%xdefine BIO_write BORINGSSL_PREFIX %+ _BIO_write
%xdefine BIO_write_all BORINGSSL_PREFIX %+ _BIO_write_all
%xdefine BIO_write_filename BORINGSSL_PREFIX %+ _BIO_write_filename
%xdefine BN_CTX_end BORINGSSL_PREFIX %+ _BN_CTX_end
%xdefine BN_CTX_free BORINGSSL_PREFIX %+ _BN_CTX_free
%xdefine BN_CTX_get BORINGSSL_PREFIX %+ _BN_CTX_get
%xdefine BN_CTX_new BORINGSSL_PREFIX %+ _BN_CTX_new
%xdefine BN_CTX_start BORINGSSL_PREFIX %+ _BN_CTX_start
%xdefine BN_GENCB_call BORINGSSL_PREFIX %+ _BN_GENCB_call
%xdefine BN_GENCB_free BORINGSSL_PREFIX %+ _BN_GENCB_free
%xdefine BN_GENCB_new BORINGSSL_PREFIX %+ _BN_GENCB_new
%xdefine BN_GENCB_set BORINGSSL_PREFIX %+ _BN_GENCB_set
%xdefine BN_MONT_CTX_copy BORINGSSL_PREFIX %+ _BN_MONT_CTX_copy
%xdefine BN_MONT_CTX_free BORINGSSL_PREFIX %+ _BN_MONT_CTX_free
%xdefine BN_MONT_CTX_new BORINGSSL_PREFIX %+ _BN_MONT_CTX_new
%xdefine BN_MONT_CTX_new_consttime BORINGSSL_PREFIX %+ _BN_MONT_CTX_new_consttime
%xdefine BN_MONT_CTX_new_for_modulus BORINGSSL_PREFIX %+ _BN_MONT_CTX_new_for_modulus
%xdefine BN_MONT_CTX_set BORINGSSL_PREFIX %+ _BN_MONT_CTX_set
%xdefine BN_MONT_CTX_set_locked BORINGSSL_PREFIX %+ _BN_MONT_CTX_set_locked
%xdefine BN_abs_is_word BORINGSSL_PREFIX %+ _BN_abs_is_word
%xdefine BN_add BORINGSSL_PREFIX %+ _BN_add
%xdefine BN_add_word BORINGSSL_PREFIX %+ _BN_add_word
%xdefine BN_asc2bn BORINGSSL_PREFIX %+ _BN_asc2bn
%xdefine BN_bin2bn BORINGSSL_PREFIX %+ _BN_bin2bn
%xdefine BN_bn2bin BORINGSSL_PREFIX %+ _BN_bn2bin
%xdefine BN_bn2bin_padded BORINGSSL_PREFIX %+ _BN_bn2bin_padded
%xdefine BN_bn2binpad BORINGSSL_PREFIX %+ _BN_bn2binpad
%xdefine BN_bn2cbb_padded BORINGSSL_PREFIX %+ _BN_bn2cbb_padded
%xdefine BN_bn2dec BORINGSSL_PREFIX %+ _BN_bn2dec
%xdefine BN_bn2hex BORINGSSL_PREFIX %+ _BN_bn2hex
%xdefine BN_bn2le_padded BORINGSSL_PREFIX %+ _BN_bn2le_padded
%xdefine BN_bn2mpi BORINGSSL_PREFIX %+ _BN_bn2mpi
%xdefine BN_clear BORINGSSL_PREFIX %+ _BN_clear
%xdefine BN_clear_bit BORINGSSL_PREFIX %+ _BN_clear_bit
%xdefine BN_clear_free BORINGSSL_PREFIX %+ _BN_clear_free
%xdefine BN_cmp BORINGSSL_PREFIX %+ _BN_cmp
%xdefine BN_cmp_word BORINGSSL_PREFIX %+ _BN_cmp_word
%xdefine BN_copy BORINGSSL_PREFIX %+ _BN_copy
%xdefine BN_count_low_zero_bits BORINGSSL_PREFIX %+ _BN_count_low_zero_bits
%xdefine BN_dec2bn BORINGSSL_PREFIX %+ _BN_dec2bn
%xdefine BN_div BORINGSSL_PREFIX %+ _BN_div
%xdefine BN_div_word BORINGSSL_PREFIX %+ _BN_div_word
%xdefine BN_dup BORINGSSL_PREFIX %+ _BN_dup
%xdefine BN_enhanced_miller_rabin_primality_test BORINGSSL_PREFIX %+ _BN_enhanced_miller_rabin_primality_test
%xdefine BN_equal_consttime BORINGSSL_PREFIX %+ _BN_equal_consttime
%xdefine BN_exp BORINGSSL_PREFIX %+ _BN_exp
%xdefine BN_free BORINGSSL_PREFIX %+ _BN_free
%xdefine BN_from_montgomery BORINGSSL_PREFIX %+ _BN_from_montgomery
%xdefine BN_gcd BORINGSSL_PREFIX %+ _BN_gcd
%xdefine BN_generate_prime_ex BORINGSSL_PREFIX %+ _BN_generate_prime_ex
%xdefine BN_get_u64 BORINGSSL_PREFIX %+ _BN_get_u64
%xdefine BN_get_word BORINGSSL_PREFIX %+ _BN_get_word
%xdefine BN_hex2bn BORINGSSL_PREFIX %+ _BN_hex2bn
%xdefine BN_init BORINGSSL_PREFIX %+ _BN_init
%xdefine BN_is_bit_set BORINGSSL_PREFIX %+ _BN_is_bit_set
%xdefine BN_is_negative BORINGSSL_PREFIX %+ _BN_is_negative
%xdefine BN_is_odd BORINGSSL_PREFIX %+ _BN_is_odd
%xdefine BN_is_one BORINGSSL_PREFIX %+ _BN_is_one
%xdefine BN_is_pow2 BORINGSSL_PREFIX %+ _BN_is_pow2
%xdefine BN_is_prime_ex BORINGSSL_PREFIX %+ _BN_is_prime_ex
%xdefine BN_is_prime_fasttest_ex BORINGSSL_PREFIX %+ _BN_is_prime_fasttest_ex
%xdefine BN_is_word BORINGSSL_PREFIX %+ _BN_is_word
%xdefine BN_is_zero BORINGSSL_PREFIX %+ _BN_is_zero
%xdefine BN_le2bn BORINGSSL_PREFIX %+ _BN_le2bn
%xdefine BN_lshift BORINGSSL_PREFIX %+ _BN_lshift
%xdefine BN_lshift1 BORINGSSL_PREFIX %+ _BN_lshift1
%xdefine BN_mask_bits BORINGSSL_PREFIX %+ _BN_mask_bits
%xdefine BN_mod_add BORINGSSL_PREFIX %+ _BN_mod_add
%xdefine BN_mod_add_quick BORINGSSL_PREFIX %+ _BN_mod_add_quick
%xdefine BN_mod_exp BORINGSSL_PREFIX %+ _BN_mod_exp
%xdefine BN_mod_exp2_mont BORINGSSL_PREFIX %+ _BN_mod_exp2_mont
%xdefine BN_mod_exp_mont BORINGSSL_PREFIX %+ _BN_mod_exp_mont
%xdefine BN_mod_exp_mont_consttime BORINGSSL_PREFIX %+ _BN_mod_exp_mont_consttime
%xdefine BN_mod_exp_mont_word BORINGSSL_PREFIX %+ _BN_mod_exp_mont_word
%xdefine BN_mod_inverse BORINGSSL_PREFIX %+ _BN_mod_inverse
%xdefine BN_mod_inverse_blinded BORINGSSL_PREFIX %+ _BN_mod_inverse_blinded
%xdefine BN_mod_inverse_odd BORINGSSL_PREFIX %+ _BN_mod_inverse_odd
%xdefine BN_mod_lshift BORINGSSL_PREFIX %+ _BN_mod_lshift
%xdefine BN_mod_lshift1 BORINGSSL_PREFIX %+ _BN_mod_lshift1
%xdefine BN_mod_lshift1_quick BORINGSSL_PREFIX %+ _BN_mod_lshift1_quick
%xdefine BN_mod_lshift_quick BORINGSSL_PREFIX %+ _BN_mod_lshift_quick
%xdefine BN_mod_mul BORINGSSL_PREFIX %+ _BN_mod_mul
%xdefine BN_mod_mul_montgomery BORINGSSL_PREFIX %+ _BN_mod_mul_montgomery
%xdefine BN_mod_pow2 BORINGSSL_PREFIX %+ _BN_mod_pow2
%xdefine BN_mod_sqr BORINGSSL_PREFIX %+ _BN_mod_sqr
%xdefine BN_mod_sqrt BORINGSSL_PREFIX %+ _BN_mod_sqrt
%xdefine BN_mod_sub BORINGSSL_PREFIX %+ _BN_mod_sub
%xdefine BN_mod_sub_quick BORINGSSL_PREFIX %+ _BN_mod_sub_quick
%xdefine BN_mod_word BORINGSSL_PREFIX %+ _BN_mod_word
%xdefine BN_mpi2bn BORINGSSL_PREFIX %+ _BN_mpi2bn
%xdefine BN_mul BORINGSSL_PREFIX %+ _BN_mul
%xdefine BN_mul_word BORINGSSL_PREFIX %+ _BN_mul_word
%xdefine BN_new BORINGSSL_PREFIX %+ _BN_new
%xdefine BN_nnmod BORINGSSL_PREFIX %+ _BN_nnmod
%xdefine BN_nnmod_pow2 BORINGSSL_PREFIX %+ _BN_nnmod_pow2
%xdefine BN_num_bits BORINGSSL_PREFIX %+ _BN_num_bits
%xdefine BN_num_bits_word BORINGSSL_PREFIX %+ _BN_num_bits_word
%xdefine BN_num_bytes BORINGSSL_PREFIX %+ _BN_num_bytes
%xdefine BN_one BORINGSSL_PREFIX %+ _BN_one
%xdefine BN_primality_test BORINGSSL_PREFIX %+ _BN_primality_test
%xdefine BN_print BORINGSSL_PREFIX %+ _BN_print
%xdefine BN_print_fp BORINGSSL_PREFIX %+ _BN_print_fp
%xdefine BN_pseudo_rand BORINGSSL_PREFIX %+ _BN_pseudo_rand
%xdefine BN_pseudo_rand_range BORINGSSL_PREFIX %+ _BN_pseudo_rand_range
%xdefine BN_rand BORINGSSL_PREFIX %+ _BN_rand
%xdefine BN_rand_range BORINGSSL_PREFIX %+ _BN_rand_range
%xdefine BN_rand_range_ex BORINGSSL_PREFIX %+ _BN_rand_range_ex
%xdefine BN_rshift BORINGSSL_PREFIX %+ _BN_rshift
%xdefine BN_rshift1 BORINGSSL_PREFIX %+ _BN_rshift1
%xdefine BN_set_bit BORINGSSL_PREFIX %+ _BN_set_bit
%xdefine BN_set_negative BORINGSSL_PREFIX %+ _BN_set_negative
%xdefine BN_set_u64 BORINGSSL_PREFIX %+ _BN_set_u64
%xdefine BN_set_word BORINGSSL_PREFIX %+ _BN_set_word
%xdefine BN_sqr BORINGSSL_PREFIX %+ _BN_sqr
%xdefine BN_sqrt BORINGSSL_PREFIX %+ _BN_sqrt
%xdefine BN_sub BORINGSSL_PREFIX %+ _BN_sub
%xdefine BN_sub_word BORINGSSL_PREFIX %+ _BN_sub_word
%xdefine BN_to_montgomery BORINGSSL_PREFIX %+ _BN_to_montgomery
%xdefine BN_uadd BORINGSSL_PREFIX %+ _BN_uadd
%xdefine BN_ucmp BORINGSSL_PREFIX %+ _BN_ucmp
%xdefine BN_usub BORINGSSL_PREFIX %+ _BN_usub
%xdefine BN_value_one BORINGSSL_PREFIX %+ _BN_value_one
%xdefine BN_zero BORINGSSL_PREFIX %+ _BN_zero
%xdefine CBB_add_asn1 BORINGSSL_PREFIX %+ _CBB_add_asn1
%xdefine CBB_add_asn1_bool BORINGSSL_PREFIX %+ _CBB_add_asn1_bool
%xdefine CBB_add_asn1_int64 BORINGSSL_PREFIX %+ _CBB_add_asn1_int64
%xdefine CBB_add_asn1_octet_string BORINGSSL_PREFIX %+ _CBB_add_asn1_octet_string
%xdefine CBB_add_asn1_oid_from_text BORINGSSL_PREFIX %+ _CBB_add_asn1_oid_from_text
%xdefine CBB_add_asn1_uint64 BORINGSSL_PREFIX %+ _CBB_add_asn1_uint64
%xdefine CBB_add_bytes BORINGSSL_PREFIX %+ _CBB_add_bytes
%xdefine CBB_add_space BORINGSSL_PREFIX %+ _CBB_add_space
%xdefine CBB_add_u16 BORINGSSL_PREFIX %+ _CBB_add_u16
%xdefine CBB_add_u16_length_prefixed BORINGSSL_PREFIX %+ _CBB_add_u16_length_prefixed
%xdefine CBB_add_u16le BORINGSSL_PREFIX %+ _CBB_add_u16le
%xdefine CBB_add_u24 BORINGSSL_PREFIX %+ _CBB_add_u24
%xdefine CBB_add_u24_length_prefixed BORINGSSL_PREFIX %+ _CBB_add_u24_length_prefixed
%xdefine CBB_add_u32 BORINGSSL_PREFIX %+ _CBB_add_u32
%xdefine CBB_add_u32le BORINGSSL_PREFIX %+ _CBB_add_u32le
%xdefine CBB_add_u64 BORINGSSL_PREFIX %+ _CBB_add_u64
%xdefine CBB_add_u64le BORINGSSL_PREFIX %+ _CBB_add_u64le
%xdefine CBB_add_u8 BORINGSSL_PREFIX %+ _CBB_add_u8
%xdefine CBB_add_u8_length_prefixed BORINGSSL_PREFIX %+ _CBB_add_u8_length_prefixed
%xdefine CBB_add_zeros BORINGSSL_PREFIX %+ _CBB_add_zeros
%xdefine CBB_cleanup BORINGSSL_PREFIX %+ _CBB_cleanup
%xdefine CBB_data BORINGSSL_PREFIX %+ _CBB_data
%xdefine CBB_did_write BORINGSSL_PREFIX %+ _CBB_did_write
%xdefine CBB_discard_child BORINGSSL_PREFIX %+ _CBB_discard_child
%xdefine CBB_finish BORINGSSL_PREFIX %+ _CBB_finish
%xdefine CBB_finish_i2d BORINGSSL_PREFIX %+ _CBB_finish_i2d
%xdefine CBB_flush BORINGSSL_PREFIX %+ _CBB_flush
%xdefine CBB_flush_asn1_set_of BORINGSSL_PREFIX %+ _CBB_flush_asn1_set_of
%xdefine CBB_init BORINGSSL_PREFIX %+ _CBB_init
%xdefine CBB_init_fixed BORINGSSL_PREFIX %+ _CBB_init_fixed
%xdefine CBB_len BORINGSSL_PREFIX %+ _CBB_len
%xdefine CBB_reserve BORINGSSL_PREFIX %+ _CBB_reserve
%xdefine CBB_zero BORINGSSL_PREFIX %+ _CBB_zero
%xdefine CBS_asn1_ber_to_der BORINGSSL_PREFIX %+ _CBS_asn1_ber_to_der
%xdefine CBS_asn1_bitstring_has_bit BORINGSSL_PREFIX %+ _CBS_asn1_bitstring_has_bit
%xdefine CBS_asn1_oid_to_text BORINGSSL_PREFIX %+ _CBS_asn1_oid_to_text
%xdefine CBS_contains_zero_byte BORINGSSL_PREFIX %+ _CBS_contains_zero_byte
%xdefine CBS_copy_bytes BORINGSSL_PREFIX %+ _CBS_copy_bytes
%xdefine CBS_data BORINGSSL_PREFIX %+ _CBS_data
%xdefine CBS_get_any_asn1 BORINGSSL_PREFIX %+ _CBS_get_any_asn1
%xdefine CBS_get_any_asn1_element BORINGSSL_PREFIX %+ _CBS_get_any_asn1_element
%xdefine CBS_get_any_ber_asn1_element BORINGSSL_PREFIX %+ _CBS_get_any_ber_asn1_element
%xdefine CBS_get_asn1 BORINGSSL_PREFIX %+ _CBS_get_asn1
%xdefine CBS_get_asn1_bool BORINGSSL_PREFIX %+ _CBS_get_asn1_bool
%xdefine CBS_get_asn1_element BORINGSSL_PREFIX %+ _CBS_get_asn1_element
%xdefine CBS_get_asn1_implicit_string BORINGSSL_PREFIX %+ _CBS_get_asn1_implicit_string
%xdefine CBS_get_asn1_int64 BORINGSSL_PREFIX %+ _CBS_get_asn1_int64
%xdefine CBS_get_asn1_uint64 BORINGSSL_PREFIX %+ _CBS_get_asn1_uint64
%xdefine CBS_get_bytes BORINGSSL_PREFIX %+ _CBS_get_bytes
%xdefine CBS_get_last_u8 BORINGSSL_PREFIX %+ _CBS_get_last_u8
%xdefine CBS_get_optional_asn1 BORINGSSL_PREFIX %+ _CBS_get_optional_asn1
%xdefine CBS_get_optional_asn1_bool BORINGSSL_PREFIX %+ _CBS_get_optional_asn1_bool
%xdefine CBS_get_optional_asn1_octet_string BORINGSSL_PREFIX %+ _CBS_get_optional_asn1_octet_string
%xdefine CBS_get_optional_asn1_uint64 BORINGSSL_PREFIX %+ _CBS_get_optional_asn1_uint64
%xdefine CBS_get_u16 BORINGSSL_PREFIX %+ _CBS_get_u16
%xdefine CBS_get_u16_length_prefixed BORINGSSL_PREFIX %+ _CBS_get_u16_length_prefixed
%xdefine CBS_get_u16le BORINGSSL_PREFIX %+ _CBS_get_u16le
%xdefine CBS_get_u24 BORINGSSL_PREFIX %+ _CBS_get_u24
%xdefine CBS_get_u24_length_prefixed BORINGSSL_PREFIX %+ _CBS_get_u24_length_prefixed
%xdefine CBS_get_u32 BORINGSSL_PREFIX %+ _CBS_get_u32
%xdefine CBS_get_u32le BORINGSSL_PREFIX %+ _CBS_get_u32le
%xdefine CBS_get_u64 BORINGSSL_PREFIX %+ _CBS_get_u64
%xdefine CBS_get_u64le BORINGSSL_PREFIX %+ _CBS_get_u64le
%xdefine CBS_get_u8 BORINGSSL_PREFIX %+ _CBS_get_u8
%xdefine CBS_get_u8_length_prefixed BORINGSSL_PREFIX %+ _CBS_get_u8_length_prefixed
%xdefine CBS_get_until_first BORINGSSL_PREFIX %+ _CBS_get_until_first
%xdefine CBS_init BORINGSSL_PREFIX %+ _CBS_init
%xdefine CBS_is_unsigned_asn1_integer BORINGSSL_PREFIX %+ _CBS_is_unsigned_asn1_integer
%xdefine CBS_is_valid_asn1_bitstring BORINGSSL_PREFIX %+ _CBS_is_valid_asn1_bitstring
%xdefine CBS_is_valid_asn1_integer BORINGSSL_PREFIX %+ _CBS_is_valid_asn1_integer
%xdefine CBS_len BORINGSSL_PREFIX %+ _CBS_len
%xdefine CBS_mem_equal BORINGSSL_PREFIX %+ _CBS_mem_equal
%xdefine CBS_peek_asn1_tag BORINGSSL_PREFIX %+ _CBS_peek_asn1_tag
%xdefine CBS_skip BORINGSSL_PREFIX %+ _CBS_skip
%xdefine CBS_stow BORINGSSL_PREFIX %+ _CBS_stow
%xdefine CBS_strdup BORINGSSL_PREFIX %+ _CBS_strdup
%xdefine CRYPTO_MUTEX_cleanup BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_cleanup
%xdefine CRYPTO_MUTEX_init BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_init
%xdefine CRYPTO_MUTEX_lock_read BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_lock_read
%xdefine CRYPTO_MUTEX_lock_write BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_lock_write
%xdefine CRYPTO_MUTEX_unlock_read BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_unlock_read
%xdefine CRYPTO_MUTEX_unlock_write BORINGSSL_PREFIX %+ _CRYPTO_MUTEX_unlock_write
%xdefine CRYPTO_POLYVAL_finish BORINGSSL_PREFIX %+ _CRYPTO_POLYVAL_finish
%xdefine CRYPTO_POLYVAL_init BORINGSSL_PREFIX %+ _CRYPTO_POLYVAL_init
%xdefine CRYPTO_POLYVAL_update_blocks BORINGSSL_PREFIX %+ _CRYPTO_POLYVAL_update_blocks
%xdefine CRYPTO_STATIC_MUTEX_lock_read BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_lock_read
%xdefine CRYPTO_STATIC_MUTEX_lock_write BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_lock_write
%xdefine CRYPTO_STATIC_MUTEX_unlock_read BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_unlock_read
%xdefine CRYPTO_STATIC_MUTEX_unlock_write BORINGSSL_PREFIX %+ _CRYPTO_STATIC_MUTEX_unlock_write
%xdefine CRYPTO_THREADID_current BORINGSSL_PREFIX %+ _CRYPTO_THREADID_current
%xdefine CRYPTO_THREADID_set_callback BORINGSSL_PREFIX %+ _CRYPTO_THREADID_set_callback
%xdefine CRYPTO_THREADID_set_numeric BORINGSSL_PREFIX %+ _CRYPTO_THREADID_set_numeric
%xdefine CRYPTO_THREADID_set_pointer BORINGSSL_PREFIX %+ _CRYPTO_THREADID_set_pointer
%xdefine CRYPTO_cbc128_decrypt BORINGSSL_PREFIX %+ _CRYPTO_cbc128_decrypt
%xdefine CRYPTO_cbc128_encrypt BORINGSSL_PREFIX %+ _CRYPTO_cbc128_encrypt
%xdefine CRYPTO_cfb128_1_encrypt BORINGSSL_PREFIX %+ _CRYPTO_cfb128_1_encrypt
%xdefine CRYPTO_cfb128_8_encrypt BORINGSSL_PREFIX %+ _CRYPTO_cfb128_8_encrypt
%xdefine CRYPTO_cfb128_encrypt BORINGSSL_PREFIX %+ _CRYPTO_cfb128_encrypt
%xdefine CRYPTO_cleanup_all_ex_data BORINGSSL_PREFIX %+ _CRYPTO_cleanup_all_ex_data
%xdefine CRYPTO_ctr128_encrypt BORINGSSL_PREFIX %+ _CRYPTO_ctr128_encrypt
%xdefine CRYPTO_ctr128_encrypt_ctr32 BORINGSSL_PREFIX %+ _CRYPTO_ctr128_encrypt_ctr32
%xdefine CRYPTO_fork_detect_ignore_madv_wipeonfork_for_testing BORINGSSL_PREFIX %+ _CRYPTO_fork_detect_ignore_madv_wipeonfork_for_testing
%xdefine CRYPTO_free BORINGSSL_PREFIX %+ _CRYPTO_free
%xdefine CRYPTO_free_ex_data BORINGSSL_PREFIX %+ _CRYPTO_free_ex_data
%xdefine CRYPTO_gcm128_aad BORINGSSL_PREFIX %+ _CRYPTO_gcm128_aad
%xdefine CRYPTO_gcm128_decrypt BORINGSSL_PREFIX %+ _CRYPTO_gcm128_decrypt
%xdefine CRYPTO_gcm128_decrypt_ctr32 BORINGSSL_PREFIX %+ _CRYPTO_gcm128_decrypt_ctr32
%xdefine CRYPTO_gcm128_encrypt BORINGSSL_PREFIX %+ _CRYPTO_gcm128_encrypt
%xdefine CRYPTO_gcm128_encrypt_ctr32 BORINGSSL_PREFIX %+ _CRYPTO_gcm128_encrypt_ctr32
%xdefine CRYPTO_gcm128_finish BORINGSSL_PREFIX %+ _CRYPTO_gcm128_finish
%xdefine CRYPTO_gcm128_init_key BORINGSSL_PREFIX %+ _CRYPTO_gcm128_init_key
%xdefine CRYPTO_gcm128_setiv BORINGSSL_PREFIX %+ _CRYPTO_gcm128_setiv
%xdefine CRYPTO_gcm128_tag BORINGSSL_PREFIX %+ _CRYPTO_gcm128_tag
%xdefine CRYPTO_get_dynlock_create_callback BORINGSSL_PREFIX %+ _CRYPTO_get_dynlock_create_callback
%xdefine CRYPTO_get_dynlock_destroy_callback BORINGSSL_PREFIX %+ _CRYPTO_get_dynlock_destroy_callback
%xdefine CRYPTO_get_dynlock_lock_callback BORINGSSL_PREFIX %+ _CRYPTO_get_dynlock_lock_callback
%xdefine CRYPTO_get_ex_data BORINGSSL_PREFIX %+ _CRYPTO_get_ex_data
%xdefine CRYPTO_get_ex_new_index BORINGSSL_PREFIX %+ _CRYPTO_get_ex_new_index
%xdefine CRYPTO_get_fork_generation BORINGSSL_PREFIX %+ _CRYPTO_get_fork_generation
%xdefine CRYPTO_get_lock_name BORINGSSL_PREFIX %+ _CRYPTO_get_lock_name
%xdefine CRYPTO_get_locking_callback BORINGSSL_PREFIX %+ _CRYPTO_get_locking_callback
%xdefine CRYPTO_get_thread_local BORINGSSL_PREFIX %+ _CRYPTO_get_thread_local
%xdefine CRYPTO_ghash_init BORINGSSL_PREFIX %+ _CRYPTO_ghash_init
%xdefine CRYPTO_has_asm BORINGSSL_PREFIX %+ _CRYPTO_has_asm
%xdefine CRYPTO_init_sysrand BORINGSSL_PREFIX %+ _CRYPTO_init_sysrand
%xdefine CRYPTO_is_confidential_build BORINGSSL_PREFIX %+ _CRYPTO_is_confidential_build
%xdefine CRYPTO_library_init BORINGSSL_PREFIX %+ _CRYPTO_library_init
%xdefine CRYPTO_malloc BORINGSSL_PREFIX %+ _CRYPTO_malloc
%xdefine CRYPTO_malloc_init BORINGSSL_PREFIX %+ _CRYPTO_malloc_init
%xdefine CRYPTO_memcmp BORINGSSL_PREFIX %+ _CRYPTO_memcmp
%xdefine CRYPTO_new_ex_data BORINGSSL_PREFIX %+ _CRYPTO_new_ex_data
%xdefine CRYPTO_num_locks BORINGSSL_PREFIX %+ _CRYPTO_num_locks
%xdefine CRYPTO_ofb128_encrypt BORINGSSL_PREFIX %+ _CRYPTO_ofb128_encrypt
%xdefine CRYPTO_once BORINGSSL_PREFIX %+ _CRYPTO_once
%xdefine CRYPTO_pre_sandbox_init BORINGSSL_PREFIX %+ _CRYPTO_pre_sandbox_init
%xdefine CRYPTO_rdrand BORINGSSL_PREFIX %+ _CRYPTO_rdrand
%xdefine CRYPTO_rdrand_multiple8_buf BORINGSSL_PREFIX %+ _CRYPTO_rdrand_multiple8_buf
%xdefine CRYPTO_realloc BORINGSSL_PREFIX %+ _CRYPTO_realloc
%xdefine CRYPTO_refcount_dec_and_test_zero BORINGSSL_PREFIX %+ _CRYPTO_refcount_dec_and_test_zero
%xdefine CRYPTO_refcount_inc BORINGSSL_PREFIX %+ _CRYPTO_refcount_inc
%xdefine CRYPTO_set_add_lock_callback BORINGSSL_PREFIX %+ _CRYPTO_set_add_lock_callback
%xdefine CRYPTO_set_dynlock_create_callback BORINGSSL_PREFIX %+ _CRYPTO_set_dynlock_create_callback
%xdefine CRYPTO_set_dynlock_destroy_callback BORINGSSL_PREFIX %+ _CRYPTO_set_dynlock_destroy_callback
%xdefine CRYPTO_set_dynlock_lock_callback BORINGSSL_PREFIX %+ _CRYPTO_set_dynlock_lock_callback
%xdefine CRYPTO_set_ex_data BORINGSSL_PREFIX %+ _CRYPTO_set_ex_data
%xdefine CRYPTO_set_id_callback BORINGSSL_PREFIX %+ _CRYPTO_set_id_callback
%xdefine CRYPTO_set_locking_callback BORINGSSL_PREFIX %+ _CRYPTO_set_locking_callback
%xdefine CRYPTO_set_thread_local BORINGSSL_PREFIX %+ _CRYPTO_set_thread_local
%xdefine CRYPTO_sysrand BORINGSSL_PREFIX %+ _CRYPTO_sysrand
%xdefine CRYPTO_sysrand_for_seed BORINGSSL_PREFIX %+ _CRYPTO_sysrand_for_seed
%xdefine CRYPTO_sysrand_if_available BORINGSSL_PREFIX %+ _CRYPTO_sysrand_if_available
%xdefine CTR_DRBG_clear BORINGSSL_PREFIX %+ _CTR_DRBG_clear
%xdefine CTR_DRBG_generate BORINGSSL_PREFIX %+ _CTR_DRBG_generate
%xdefine CTR_DRBG_init BORINGSSL_PREFIX %+ _CTR_DRBG_init
%xdefine CTR_DRBG_reseed BORINGSSL_PREFIX %+ _CTR_DRBG_reseed
%xdefine ENGINE_load_builtin_engines BORINGSSL_PREFIX %+ _ENGINE_load_builtin_engines
%xdefine ENGINE_register_all_complete BORINGSSL_PREFIX %+ _ENGINE_register_all_complete
%xdefine ERR_SAVE_STATE_free BORINGSSL_PREFIX %+ _ERR_SAVE_STATE_free
%xdefine ERR_add_error_data BORINGSSL_PREFIX %+ _ERR_add_error_data
%xdefine ERR_add_error_dataf BORINGSSL_PREFIX %+ _ERR_add_error_dataf
%xdefine ERR_clear_error BORINGSSL_PREFIX %+ _ERR_clear_error
%xdefine ERR_clear_system_error BORINGSSL_PREFIX %+ _ERR_clear_system_error
%xdefine ERR_error_string BORINGSSL_PREFIX %+ _ERR_error_string
%xdefine ERR_error_string_n BORINGSSL_PREFIX %+ _ERR_error_string_n
%xdefine ERR_free_strings BORINGSSL_PREFIX %+ _ERR_free_strings
%xdefine ERR_func_error_string BORINGSSL_PREFIX %+ _ERR_func_error_string
%xdefine ERR_get_error BORINGSSL_PREFIX %+ _ERR_get_error
%xdefine ERR_get_error_line BORINGSSL_PREFIX %+ _ERR_get_error_line
%xdefine ERR_get_error_line_data BORINGSSL_PREFIX %+ _ERR_get_error_line_data
%xdefine ERR_get_next_error_library BORINGSSL_PREFIX %+ _ERR_get_next_error_library
%xdefine ERR_lib_error_string BORINGSSL_PREFIX %+ _ERR_lib_error_string
%xdefine ERR_load_BIO_strings BORINGSSL_PREFIX %+ _ERR_load_BIO_strings
%xdefine ERR_load_ERR_strings BORINGSSL_PREFIX %+ _ERR_load_ERR_strings
%xdefine ERR_load_RAND_strings BORINGSSL_PREFIX %+ _ERR_load_RAND_strings
%xdefine ERR_load_crypto_strings BORINGSSL_PREFIX %+ _ERR_load_crypto_strings
%xdefine ERR_peek_error BORINGSSL_PREFIX %+ _ERR_peek_error
%xdefine ERR_peek_error_line BORINGSSL_PREFIX %+ _ERR_peek_error_line
%xdefine ERR_peek_error_line_data BORINGSSL_PREFIX %+ _ERR_peek_error_line_data
%xdefine ERR_peek_last_error BORINGSSL_PREFIX %+ _ERR_peek_last_error
%xdefine ERR_peek_last_error_line BORINGSSL_PREFIX %+ _ERR_peek_last_error_line
%xdefine ERR_peek_last_error_line_data BORINGSSL_PREFIX %+ _ERR_peek_last_error_line_data
%xdefine ERR_pop_to_mark BORINGSSL_PREFIX %+ _ERR_pop_to_mark
%xdefine ERR_print_errors BORINGSSL_PREFIX %+ _ERR_print_errors
%xdefine ERR_print_errors_cb BORINGSSL_PREFIX %+ _ERR_print_errors_cb
%xdefine ERR_print_errors_fp BORINGSSL_PREFIX %+ _ERR_print_errors_fp
%xdefine ERR_put_error BORINGSSL_PREFIX %+ _ERR_put_error
%xdefine ERR_reason_error_string BORINGSSL_PREFIX %+ _ERR_reason_error_string
%xdefine ERR_remove_state BORINGSSL_PREFIX %+ _ERR_remove_state
%xdefine ERR_remove_thread_state BORINGSSL_PREFIX %+ _ERR_remove_thread_state
%xdefine ERR_restore_state BORINGSSL_PREFIX %+ _ERR_restore_state
%xdefine ERR_save_state BORINGSSL_PREFIX %+ _ERR_save_state
%xdefine ERR_set_error_data BORINGSSL_PREFIX %+ _ERR_set_error_data
%xdefine ERR_set_mark BORINGSSL_PREFIX %+ _ERR_set_mark
%xdefine EVP_CIPHER_CTX_block_size BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_block_size
%xdefine EVP_CIPHER_CTX_cipher BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_cipher
%xdefine EVP_CIPHER_CTX_cleanup BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_cleanup
%xdefine EVP_CIPHER_CTX_copy BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_copy
%xdefine EVP_CIPHER_CTX_ctrl BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_ctrl
%xdefine EVP_CIPHER_CTX_encrypting BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_encrypting
%xdefine EVP_CIPHER_CTX_flags BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_flags
%xdefine EVP_CIPHER_CTX_free BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_free
%xdefine EVP_CIPHER_CTX_get_app_data BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_get_app_data
%xdefine EVP_CIPHER_CTX_init BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_init
%xdefine EVP_CIPHER_CTX_iv_length BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_iv_length
%xdefine EVP_CIPHER_CTX_key_length BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_key_length
%xdefine EVP_CIPHER_CTX_mode BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_mode
%xdefine EVP_CIPHER_CTX_new BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_new
%xdefine EVP_CIPHER_CTX_nid BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_nid
%xdefine EVP_CIPHER_CTX_reset BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_reset
%xdefine EVP_CIPHER_CTX_set_app_data BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_app_data
%xdefine EVP_CIPHER_CTX_set_flags BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_flags
%xdefine EVP_CIPHER_CTX_set_key_length BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_key_length
%xdefine EVP_CIPHER_CTX_set_padding BORINGSSL_PREFIX %+ _EVP_CIPHER_CTX_set_padding
%xdefine EVP_CIPHER_block_size BORINGSSL_PREFIX %+ _EVP_CIPHER_block_size
%xdefine EVP_CIPHER_flags BORINGSSL_PREFIX %+ _EVP_CIPHER_flags
%xdefine EVP_CIPHER_iv_length BORINGSSL_PREFIX %+ _EVP_CIPHER_iv_length
%xdefine EVP_CIPHER_key_length BORINGSSL_PREFIX %+ _EVP_CIPHER_key_length
%xdefine EVP_CIPHER_mode BORINGSSL_PREFIX %+ _EVP_CIPHER_mode
%xdefine EVP_CIPHER_nid BORINGSSL_PREFIX %+ _EVP_CIPHER_nid
%xdefine EVP_Cipher BORINGSSL_PREFIX %+ _EVP_Cipher
%xdefine EVP_CipherFinal BORINGSSL_PREFIX %+ _EVP_CipherFinal
%xdefine EVP_CipherFinal_ex BORINGSSL_PREFIX %+ _EVP_CipherFinal_ex
%xdefine EVP_CipherInit BORINGSSL_PREFIX %+ _EVP_CipherInit
%xdefine EVP_CipherInit_ex BORINGSSL_PREFIX %+ _EVP_CipherInit_ex
%xdefine EVP_CipherUpdate BORINGSSL_PREFIX %+ _EVP_CipherUpdate
%xdefine EVP_DecryptFinal BORINGSSL_PREFIX %+ _EVP_DecryptFinal
%xdefine EVP_DecryptFinal_ex BORINGSSL_PREFIX %+ _EVP_DecryptFinal_ex
%xdefine EVP_DecryptInit BORINGSSL_PREFIX %+ _EVP_DecryptInit
%xdefine EVP_DecryptInit_ex BORINGSSL_PREFIX %+ _EVP_DecryptInit_ex
%xdefine EVP_DecryptUpdate BORINGSSL_PREFIX %+ _EVP_DecryptUpdate
%xdefine EVP_EncryptFinal BORINGSSL_PREFIX %+ _EVP_EncryptFinal
%xdefine EVP_EncryptFinal_ex BORINGSSL_PREFIX %+ _EVP_EncryptFinal_ex
%xdefine EVP_EncryptInit BORINGSSL_PREFIX %+ _EVP_EncryptInit
%xdefine EVP_EncryptInit_ex BORINGSSL_PREFIX %+ _EVP_EncryptInit_ex
%xdefine EVP_EncryptUpdate BORINGSSL_PREFIX %+ _EVP_EncryptUpdate
%xdefine EVP_add_cipher_alias BORINGSSL_PREFIX %+ _EVP_add_cipher_alias
%xdefine EVP_aead_aes_128_gcm BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm
%xdefine EVP_aead_aes_128_gcm_randnonce BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm_randnonce
%xdefine EVP_aead_aes_128_gcm_tls12 BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm_tls12
%xdefine EVP_aead_aes_128_gcm_tls13 BORINGSSL_PREFIX %+ _EVP_aead_aes_128_gcm_tls13
%xdefine EVP_aead_aes_192_gcm BORINGSSL_PREFIX %+ _EVP_aead_aes_192_gcm
%xdefine EVP_aead_aes_256_gcm BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm
%xdefine EVP_aead_aes_256_gcm_randnonce BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm_randnonce
%xdefine EVP_aead_aes_256_gcm_tls12 BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm_tls12
%xdefine EVP_aead_aes_256_gcm_tls13 BORINGSSL_PREFIX %+ _EVP_aead_aes_256_gcm_tls13
%xdefine EVP_aes_128_cbc BORINGSSL_PREFIX %+ _EVP_aes_128_cbc
%xdefine EVP_aes_128_ctr BORINGSSL_PREFIX %+ _EVP_aes_128_ctr
%xdefine EVP_aes_128_ecb BORINGSSL_PREFIX %+ _EVP_aes_128_ecb
%xdefine EVP_aes_128_gcm BORINGSSL_PREFIX %+ _EVP_aes_128_gcm
%xdefine EVP_aes_128_ofb BORINGSSL_PREFIX %+ _EVP_aes_128_ofb
%xdefine EVP_aes_192_cbc BORINGSSL_PREFIX %+ _EVP_aes_192_cbc
%xdefine EVP_aes_192_ctr BORINGSSL_PREFIX %+ _EVP_aes_192_ctr
%xdefine EVP_aes_192_ecb BORINGSSL_PREFIX %+ _EVP_aes_192_ecb
%xdefine EVP_aes_192_gcm BORINGSSL_PREFIX %+ _EVP_aes_192_gcm
%xdefine EVP_aes_192_ofb BORINGSSL_PREFIX %+ _EVP_aes_192_ofb
%xdefine EVP_aes_256_cbc BORINGSSL_PREFIX %+ _EVP_aes_256_cbc
%xdefine EVP_aes_256_ctr BORINGSSL_PREFIX %+ _EVP_aes_256_ctr
%xdefine EVP_aes_256_ecb BORINGSSL_PREFIX %+ _EVP_aes_256_ecb
%xdefine EVP_aes_256_gcm BORINGSSL_PREFIX %+ _EVP_aes_256_gcm
%xdefine EVP_aes_256_ofb BORINGSSL_PREFIX %+ _EVP_aes_256_ofb
%xdefine EVP_has_aes_hardware BORINGSSL_PREFIX %+ _EVP_has_aes_hardware
%xdefine OPENSSL_cleanse BORINGSSL_PREFIX %+ _OPENSSL_cleanse
%xdefine OPENSSL_cleanup BORINGSSL_PREFIX %+ _OPENSSL_cleanup
%xdefine OPENSSL_clear_free BORINGSSL_PREFIX %+ _OPENSSL_clear_free
%xdefine OPENSSL_cpuid_setup BORINGSSL_PREFIX %+ _OPENSSL_cpuid_setup
%xdefine OPENSSL_free BORINGSSL_PREFIX %+ _OPENSSL_free
%xdefine OPENSSL_hash32 BORINGSSL_PREFIX %+ _OPENSSL_hash32
%xdefine OPENSSL_ia32cap_P BORINGSSL_PREFIX %+ _OPENSSL_ia32cap_P
%xdefine OPENSSL_init_crypto BORINGSSL_PREFIX %+ _OPENSSL_init_crypto
%xdefine OPENSSL_load_builtin_modules BORINGSSL_PREFIX %+ _OPENSSL_load_builtin_modules
%xdefine OPENSSL_malloc BORINGSSL_PREFIX %+ _OPENSSL_malloc
%xdefine OPENSSL_malloc_init BORINGSSL_PREFIX %+ _OPENSSL_malloc_init
%xdefine OPENSSL_memdup BORINGSSL_PREFIX %+ _OPENSSL_memdup
%xdefine OPENSSL_realloc BORINGSSL_PREFIX %+ _OPENSSL_realloc
%xdefine OPENSSL_strcasecmp BORINGSSL_PREFIX %+ _OPENSSL_strcasecmp
%xdefine OPENSSL_strdup BORINGSSL_PREFIX %+ _OPENSSL_strdup
%xdefine OPENSSL_strhash BORINGSSL_PREFIX %+ _OPENSSL_strhash
%xdefine OPENSSL_strlcat BORINGSSL_PREFIX %+ _OPENSSL_strlcat
%xdefine OPENSSL_strlcpy BORINGSSL_PREFIX %+ _OPENSSL_strlcpy
%xdefine OPENSSL_strncasecmp BORINGSSL_PREFIX %+ _OPENSSL_strncasecmp
%xdefine OPENSSL_strndup BORINGSSL_PREFIX %+ _OPENSSL_strndup
%xdefine OPENSSL_strnlen BORINGSSL_PREFIX %+ _OPENSSL_strnlen
%xdefine OPENSSL_tolower BORINGSSL_PREFIX %+ _OPENSSL_tolower
%xdefine OpenSSL_version BORINGSSL_PREFIX %+ _OpenSSL_version
%xdefine OpenSSL_version_num BORINGSSL_PREFIX %+ _OpenSSL_version_num
%xdefine RAND_OpenSSL BORINGSSL_PREFIX %+ _RAND_OpenSSL
%xdefine RAND_SSLeay BORINGSSL_PREFIX %+ _RAND_SSLeay
%xdefine RAND_add BORINGSSL_PREFIX %+ _RAND_add
%xdefine RAND_bytes BORINGSSL_PREFIX %+ _RAND_bytes
%xdefine RAND_bytes_with_additional_data BORINGSSL_PREFIX %+ _RAND_bytes_with_additional_data
%xdefine RAND_cleanup BORINGSSL_PREFIX %+ _RAND_cleanup
%xdefine RAND_egd BORINGSSL_PREFIX %+ _RAND_egd
%xdefine RAND_enable_fork_unsafe_buffering BORINGSSL_PREFIX %+ _RAND_enable_fork_unsafe_buffering
%xdefine RAND_file_name BORINGSSL_PREFIX %+ _RAND_file_name
%xdefine RAND_get_rand_method BORINGSSL_PREFIX %+ _RAND_get_rand_method
%xdefine RAND_load_file BORINGSSL_PREFIX %+ _RAND_load_file
%xdefine RAND_poll BORINGSSL_PREFIX %+ _RAND_poll
%xdefine RAND_pseudo_bytes BORINGSSL_PREFIX %+ _RAND_pseudo_bytes
%xdefine RAND_seed BORINGSSL_PREFIX %+ _RAND_seed
%xdefine RAND_set_rand_method BORINGSSL_PREFIX %+ _RAND_set_rand_method
%xdefine RAND_status BORINGSSL_PREFIX %+ _RAND_status
%xdefine RSAZ_1024_mod_exp_avx2 BORINGSSL_PREFIX %+ _RSAZ_1024_mod_exp_avx2
%xdefine SSLeay BORINGSSL_PREFIX %+ _SSLeay
%xdefine SSLeay_version BORINGSSL_PREFIX %+ _SSLeay_version
%xdefine __clang_at_available_requires_core_foundation_framework BORINGSSL_PREFIX %+ ___clang_at_available_requires_core_foundation_framework
%xdefine aes_ctr_set_key BORINGSSL_PREFIX %+ _aes_ctr_set_key
%xdefine aes_hw_cbc_encrypt BORINGSSL_PREFIX %+ _aes_hw_cbc_encrypt
%xdefine aes_hw_ctr32_encrypt_blocks BORINGSSL_PREFIX %+ _aes_hw_ctr32_encrypt_blocks
%xdefine aes_hw_decrypt BORINGSSL_PREFIX %+ _aes_hw_decrypt
%xdefine aes_hw_ecb_encrypt BORINGSSL_PREFIX %+ _aes_hw_ecb_encrypt
%xdefine aes_hw_encrypt BORINGSSL_PREFIX %+ _aes_hw_encrypt
%xdefine aes_hw_set_decrypt_key BORINGSSL_PREFIX %+ _aes_hw_set_decrypt_key
%xdefine aes_hw_set_encrypt_key BORINGSSL_PREFIX %+ _aes_hw_set_encrypt_key
%xdefine aes_nohw_cbc_encrypt BORINGSSL_PREFIX %+ _aes_nohw_cbc_encrypt
%xdefine aes_nohw_ctr32_encrypt_blocks BORINGSSL_PREFIX %+ _aes_nohw_ctr32_encrypt_blocks
%xdefine aes_nohw_decrypt BORINGSSL_PREFIX %+ _aes_nohw_decrypt
%xdefine aes_nohw_encrypt BORINGSSL_PREFIX %+ _aes_nohw_encrypt
%xdefine aes_nohw_set_decrypt_key BORINGSSL_PREFIX %+ _aes_nohw_set_decrypt_key
%xdefine aes_nohw_set_encrypt_key BORINGSSL_PREFIX %+ _aes_nohw_set_encrypt_key
%xdefine aesni_gcm_decrypt BORINGSSL_PREFIX %+ _aesni_gcm_decrypt
%xdefine aesni_gcm_encrypt BORINGSSL_PREFIX %+ _aesni_gcm_encrypt
%xdefine beeu_mod_inverse_vartime BORINGSSL_PREFIX %+ _beeu_mod_inverse_vartime
%xdefine bn_abs_sub_consttime BORINGSSL_PREFIX %+ _bn_abs_sub_consttime
%xdefine bn_add_words BORINGSSL_PREFIX %+ _bn_add_words
%xdefine bn_copy_words BORINGSSL_PREFIX %+ _bn_copy_words
%xdefine bn_div_consttime BORINGSSL_PREFIX %+ _bn_div_consttime
%xdefine bn_expand BORINGSSL_PREFIX %+ _bn_expand
%xdefine bn_fits_in_words BORINGSSL_PREFIX %+ _bn_fits_in_words
%xdefine bn_from_montgomery BORINGSSL_PREFIX %+ _bn_from_montgomery
%xdefine bn_from_montgomery_small BORINGSSL_PREFIX %+ _bn_from_montgomery_small
%xdefine bn_gather5 BORINGSSL_PREFIX %+ _bn_gather5
%xdefine bn_in_range_words BORINGSSL_PREFIX %+ _bn_in_range_words
%xdefine bn_is_bit_set_words BORINGSSL_PREFIX %+ _bn_is_bit_set_words
%xdefine bn_is_relatively_prime BORINGSSL_PREFIX %+ _bn_is_relatively_prime
%xdefine bn_jacobi BORINGSSL_PREFIX %+ _bn_jacobi
%xdefine bn_lcm_consttime BORINGSSL_PREFIX %+ _bn_lcm_consttime
%xdefine bn_less_than_montgomery_R BORINGSSL_PREFIX %+ _bn_less_than_montgomery_R
%xdefine bn_less_than_words BORINGSSL_PREFIX %+ _bn_less_than_words
%xdefine bn_miller_rabin_init BORINGSSL_PREFIX %+ _bn_miller_rabin_init
%xdefine bn_miller_rabin_iteration BORINGSSL_PREFIX %+ _bn_miller_rabin_iteration
%xdefine bn_minimal_width BORINGSSL_PREFIX %+ _bn_minimal_width
%xdefine bn_mod_add_consttime BORINGSSL_PREFIX %+ _bn_mod_add_consttime
%xdefine bn_mod_add_words BORINGSSL_PREFIX %+ _bn_mod_add_words
%xdefine bn_mod_exp_base_2_consttime BORINGSSL_PREFIX %+ _bn_mod_exp_base_2_consttime
%xdefine bn_mod_exp_mont_small BORINGSSL_PREFIX %+ _bn_mod_exp_mont_small
%xdefine bn_mod_inverse0_prime_mont_small BORINGSSL_PREFIX %+ _bn_mod_inverse0_prime_mont_small
%xdefine bn_mod_inverse_consttime BORINGSSL_PREFIX %+ _bn_mod_inverse_consttime
%xdefine bn_mod_inverse_prime BORINGSSL_PREFIX %+ _bn_mod_inverse_prime
%xdefine bn_mod_inverse_secret_prime BORINGSSL_PREFIX %+ _bn_mod_inverse_secret_prime
%xdefine bn_mod_lshift1_consttime BORINGSSL_PREFIX %+ _bn_mod_lshift1_consttime
%xdefine bn_mod_lshift_consttime BORINGSSL_PREFIX %+ _bn_mod_lshift_consttime
%xdefine bn_mod_mul_montgomery_small BORINGSSL_PREFIX %+ _bn_mod_mul_montgomery_small
%xdefine bn_mod_sub_consttime BORINGSSL_PREFIX %+ _bn_mod_sub_consttime
%xdefine bn_mod_sub_words BORINGSSL_PREFIX %+ _bn_mod_sub_words
%xdefine bn_mod_u16_consttime BORINGSSL_PREFIX %+ _bn_mod_u16_consttime
%xdefine bn_mont_n0 BORINGSSL_PREFIX %+ _bn_mont_n0
%xdefine bn_mul_add_words BORINGSSL_PREFIX %+ _bn_mul_add_words
%xdefine bn_mul_comba4 BORINGSSL_PREFIX %+ _bn_mul_comba4
%xdefine bn_mul_comba8 BORINGSSL_PREFIX %+ _bn_mul_comba8
%xdefine bn_mul_consttime BORINGSSL_PREFIX %+ _bn_mul_consttime
%xdefine bn_mul_mont BORINGSSL_PREFIX %+ _bn_mul_mont
%xdefine bn_mul_mont_gather5 BORINGSSL_PREFIX %+ _bn_mul_mont_gather5
%xdefine bn_mul_small BORINGSSL_PREFIX %+ _bn_mul_small
%xdefine bn_mul_words BORINGSSL_PREFIX %+ _bn_mul_words
%xdefine bn_odd_number_is_obviously_composite BORINGSSL_PREFIX %+ _bn_odd_number_is_obviously_composite
%xdefine bn_one_to_montgomery BORINGSSL_PREFIX %+ _bn_one_to_montgomery
%xdefine bn_power5 BORINGSSL_PREFIX %+ _bn_power5
%xdefine bn_rand_range_words BORINGSSL_PREFIX %+ _bn_rand_range_words
%xdefine bn_rand_secret_range BORINGSSL_PREFIX %+ _bn_rand_secret_range
%xdefine bn_reduce_once BORINGSSL_PREFIX %+ _bn_reduce_once
%xdefine bn_reduce_once_in_place BORINGSSL_PREFIX %+ _bn_reduce_once_in_place
%xdefine bn_resize_words BORINGSSL_PREFIX %+ _bn_resize_words
%xdefine bn_rshift1_words BORINGSSL_PREFIX %+ _bn_rshift1_words
%xdefine bn_rshift_secret_shift BORINGSSL_PREFIX %+ _bn_rshift_secret_shift
%xdefine bn_rshift_words BORINGSSL_PREFIX %+ _bn_rshift_words
%xdefine bn_scatter5 BORINGSSL_PREFIX %+ _bn_scatter5
%xdefine bn_select_words BORINGSSL_PREFIX %+ _bn_select_words
%xdefine bn_set_minimal_width BORINGSSL_PREFIX %+ _bn_set_minimal_width
%xdefine bn_set_static_words BORINGSSL_PREFIX %+ _bn_set_static_words
%xdefine bn_set_words BORINGSSL_PREFIX %+ _bn_set_words
%xdefine bn_sqr8x_internal BORINGSSL_PREFIX %+ _bn_sqr8x_internal
%xdefine bn_sqr_comba4 BORINGSSL_PREFIX %+ _bn_sqr_comba4
%xdefine bn_sqr_comba8 BORINGSSL_PREFIX %+ _bn_sqr_comba8
%xdefine bn_sqr_consttime BORINGSSL_PREFIX %+ _bn_sqr_consttime
%xdefine bn_sqr_small BORINGSSL_PREFIX %+ _bn_sqr_small
%xdefine bn_sqr_words BORINGSSL_PREFIX %+ _bn_sqr_words
%xdefine bn_sqrx8x_internal BORINGSSL_PREFIX %+ _bn_sqrx8x_internal
%xdefine bn_sub_words BORINGSSL_PREFIX %+ _bn_sub_words
%xdefine bn_to_montgomery_small BORINGSSL_PREFIX %+ _bn_to_montgomery_small
%xdefine bn_uadd_consttime BORINGSSL_PREFIX %+ _bn_uadd_consttime
%xdefine bn_usub_consttime BORINGSSL_PREFIX %+ _bn_usub_consttime
%xdefine bn_wexpand BORINGSSL_PREFIX %+ _bn_wexpand
%xdefine cbb_add_latin1 BORINGSSL_PREFIX %+ _cbb_add_latin1
%xdefine cbb_add_ucs2_be BORINGSSL_PREFIX %+ _cbb_add_ucs2_be
%xdefine cbb_add_utf32_be BORINGSSL_PREFIX %+ _cbb_add_utf32_be
%xdefine cbb_add_utf8 BORINGSSL_PREFIX %+ _cbb_add_utf8
%xdefine cbb_get_utf8_len BORINGSSL_PREFIX %+ _cbb_get_utf8_len
%xdefine cbs_get_latin1 BORINGSSL_PREFIX %+ _cbs_get_latin1
%xdefine cbs_get_ucs2_be BORINGSSL_PREFIX %+ _cbs_get_ucs2_be
%xdefine cbs_get_utf32_be BORINGSSL_PREFIX %+ _cbs_get_utf32_be
%xdefine cbs_get_utf8 BORINGSSL_PREFIX %+ _cbs_get_utf8
%xdefine crypto_gcm_clmul_enabled BORINGSSL_PREFIX %+ _crypto_gcm_clmul_enabled
%xdefine ecp_nistz256_avx2_select_w7 BORINGSSL_PREFIX %+ _ecp_nistz256_avx2_select_w7
%xdefine ecp_nistz256_mul_mont BORINGSSL_PREFIX %+ _ecp_nistz256_mul_mont
%xdefine ecp_nistz256_neg BORINGSSL_PREFIX %+ _ecp_nistz256_neg
%xdefine ecp_nistz256_ord_mul_mont BORINGSSL_PREFIX %+ _ecp_nistz256_ord_mul_mont
%xdefine ecp_nistz256_ord_sqr_mont BORINGSSL_PREFIX %+ _ecp_nistz256_ord_sqr_mont
%xdefine ecp_nistz256_point_add BORINGSSL_PREFIX %+ _ecp_nistz256_point_add
%xdefine ecp_nistz256_point_add_affine BORINGSSL_PREFIX %+ _ecp_nistz256_point_add_affine
%xdefine ecp_nistz256_point_double BORINGSSL_PREFIX %+ _ecp_nistz256_point_double
%xdefine ecp_nistz256_select_w5 BORINGSSL_PREFIX %+ _ecp_nistz256_select_w5
%xdefine ecp_nistz256_select_w7 BORINGSSL_PREFIX %+ _ecp_nistz256_select_w7
%xdefine ecp_nistz256_sqr_mont BORINGSSL_PREFIX %+ _ecp_nistz256_sqr_mont
%xdefine gcm_ghash_avx BORINGSSL_PREFIX %+ _gcm_ghash_avx
%xdefine gcm_ghash_clmul BORINGSSL_PREFIX %+ _gcm_ghash_clmul
%xdefine gcm_ghash_nohw BORINGSSL_PREFIX %+ _gcm_ghash_nohw
%xdefine gcm_ghash_ssse3 BORINGSSL_PREFIX %+ _gcm_ghash_ssse3
%xdefine gcm_gmult_avx BORINGSSL_PREFIX %+ _gcm_gmult_avx
%xdefine gcm_gmult_clmul BORINGSSL_PREFIX %+ _gcm_gmult_clmul
%xdefine gcm_gmult_nohw BORINGSSL_PREFIX %+ _gcm_gmult_nohw
%xdefine gcm_gmult_ssse3 BORINGSSL_PREFIX %+ _gcm_gmult_ssse3
%xdefine gcm_init_avx BORINGSSL_PREFIX %+ _gcm_init_avx
%xdefine gcm_init_clmul BORINGSSL_PREFIX %+ _gcm_init_clmul
%xdefine gcm_init_nohw BORINGSSL_PREFIX %+ _gcm_init_nohw
%xdefine gcm_init_ssse3 BORINGSSL_PREFIX %+ _gcm_init_ssse3
%xdefine kOpenSSLReasonStringData BORINGSSL_PREFIX %+ _kOpenSSLReasonStringData
%xdefine kOpenSSLReasonValues BORINGSSL_PREFIX %+ _kOpenSSLReasonValues
%xdefine kOpenSSLReasonValuesLen BORINGSSL_PREFIX %+ _kOpenSSLReasonValuesLen
%xdefine md5_block_asm_data_order BORINGSSL_PREFIX %+ _md5_block_asm_data_order
%xdefine rand_fork_unsafe_buffering_enabled BORINGSSL_PREFIX %+ _rand_fork_unsafe_buffering_enabled
%xdefine rsaz_1024_gather5_avx2 BORINGSSL_PREFIX %+ _rsaz_1024_gather5_avx2
%xdefine rsaz_1024_mul_avx2 BORINGSSL_PREFIX %+ _rsaz_1024_mul_avx2
%xdefine rsaz_1024_norm2red_avx2 BORINGSSL_PREFIX %+ _rsaz_1024_norm2red_avx2
%xdefine rsaz_1024_red2norm_avx2 BORINGSSL_PREFIX %+ _rsaz_1024_red2norm_avx2
%xdefine rsaz_1024_scatter5_avx2 BORINGSSL_PREFIX %+ _rsaz_1024_scatter5_avx2
%xdefine rsaz_1024_sqr_avx2 BORINGSSL_PREFIX %+ _rsaz_1024_sqr_avx2
%xdefine sha1_block_data_order BORINGSSL_PREFIX %+ _sha1_block_data_order
%xdefine sha256_block_data_order BORINGSSL_PREFIX %+ _sha256_block_data_order
%xdefine sha512_block_data_order BORINGSSL_PREFIX %+ _sha512_block_data_order
%xdefine sk_deep_copy BORINGSSL_PREFIX %+ _sk_deep_copy
%xdefine sk_delete BORINGSSL_PREFIX %+ _sk_delete
%xdefine sk_delete_ptr BORINGSSL_PREFIX %+ _sk_delete_ptr
%xdefine sk_dup BORINGSSL_PREFIX %+ _sk_dup
%xdefine sk_find BORINGSSL_PREFIX %+ _sk_find
%xdefine sk_free BORINGSSL_PREFIX %+ _sk_free
%xdefine sk_insert BORINGSSL_PREFIX %+ _sk_insert
%xdefine sk_is_sorted BORINGSSL_PREFIX %+ _sk_is_sorted
%xdefine sk_new BORINGSSL_PREFIX %+ _sk_new
%xdefine sk_new_null BORINGSSL_PREFIX %+ _sk_new_null
%xdefine sk_num BORINGSSL_PREFIX %+ _sk_num
%xdefine sk_pop BORINGSSL_PREFIX %+ _sk_pop
%xdefine sk_pop_free BORINGSSL_PREFIX %+ _sk_pop_free
%xdefine sk_pop_free_ex BORINGSSL_PREFIX %+ _sk_pop_free_ex
%xdefine sk_push BORINGSSL_PREFIX %+ _sk_push
%xdefine sk_set BORINGSSL_PREFIX %+ _sk_set
%xdefine sk_set_cmp_func BORINGSSL_PREFIX %+ _sk_set_cmp_func
%xdefine sk_shift BORINGSSL_PREFIX %+ _sk_shift
%xdefine sk_sort BORINGSSL_PREFIX %+ _sk_sort
%xdefine sk_value BORINGSSL_PREFIX %+ _sk_value
%xdefine sk_zero BORINGSSL_PREFIX %+ _sk_zero
%xdefine vpaes_cbc_encrypt BORINGSSL_PREFIX %+ _vpaes_cbc_encrypt
%xdefine vpaes_ctr32_encrypt_blocks BORINGSSL_PREFIX %+ _vpaes_ctr32_encrypt_blocks
%xdefine vpaes_decrypt BORINGSSL_PREFIX %+ _vpaes_decrypt
%xdefine vpaes_encrypt BORINGSSL_PREFIX %+ _vpaes_encrypt
%xdefine vpaes_set_decrypt_key BORINGSSL_PREFIX %+ _vpaes_set_decrypt_key
%xdefine vpaes_set_encrypt_key BORINGSSL_PREFIX %+ _vpaes_set_encrypt_key
%endif
