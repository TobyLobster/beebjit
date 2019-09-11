#ifndef BEEBJIT_UTIL_H
#define BEEBJIT_UTIL_H

struct util_file_map_struct;

#include <stdint.h>
#include <unistd.h>

/* Memory mapping. */
int util_get_memory_fd(size_t size);
void* util_get_guarded_mapping(void* p_addr, size_t size);
void* util_get_guarded_mapping_from_fd(int fd, void* p_addr, size_t size);
void util_free_guarded_mapping(void* p_addr, size_t size);
void util_make_mapping_read_only(void* p_addr, size_t size);
void util_make_mapping_read_write(void* p_addr, size_t size);
void util_make_mapping_read_write_exec(void* p_addr, size_t size);
void util_make_mapping_none(void* p_addr, size_t size);
void* util_get_fixed_anonymous_mapping(void* p_addr, size_t size);
void* util_get_fixed_mapping_from_fd(int fd, void* p_addr, size_t size);

/* Buffer. */
struct util_buffer;
struct util_buffer* util_buffer_create();
void util_buffer_destroy(struct util_buffer* p_buf);
void util_buffer_setup(struct util_buffer* p_buf, uint8_t* p_mem, size_t len);
uint8_t* util_buffer_get_ptr(struct util_buffer* p_buf);
size_t util_buffer_get_pos(struct util_buffer* p_buf);
void util_buffer_set_pos(struct util_buffer* p_buf, size_t len);
size_t util_buffer_remaining(struct util_buffer* p_buf);
void util_buffer_append(struct util_buffer* p_buf,
                        struct util_buffer* p_src_buf);
void util_buffer_set_base_address(struct util_buffer* p_buf, uint8_t* p_base);
uint8_t* util_buffer_get_base_address(struct util_buffer* p_buf);

void util_buffer_add_1b(struct util_buffer* p_buf, int b1);
void util_buffer_add_2b(struct util_buffer* p_buf, int b1, int b2);
void util_buffer_add_2b_1w(struct util_buffer* p_buf, int b1, int b2, int w1);
void util_buffer_add_3b(struct util_buffer* p_buf, int b1, int b2, int b3);
void util_buffer_add_4b(struct util_buffer* p_buf,
                        int b1,
                        int b2,
                        int b3,
                        int b4);
void util_buffer_add_5b(struct util_buffer* p_buf,
                        int b1,
                        int b2,
                        int b3,
                        int b4,
                        int b5);
void util_buffer_add_int(struct util_buffer* p_buf, ssize_t i);
void util_buffer_add_chunk(struct util_buffer* p_buf, void* p_src, size_t size);
void util_buffer_fill_to_end(struct util_buffer* p_buf, char value);
void util_buffer_fill(struct util_buffer* p_buf, char value, size_t len);

/* File. */
uint64_t util_file_get_handle(const char* p_file_name, int writeable);
void util_file_close_handle(uint64_t handle);
uint64_t util_file_handle_get_size(uint64_t handle);
void util_file_handle_write(uint64_t handle,
                            const void* p_buf,
                            uint64_t length);
uint64_t util_file_handle_read(uint64_t handle, void* p_buf, uint64_t length);

size_t util_file_read(uint8_t* p_buf,
                      size_t max_size,
                      const char* p_file_name);
void util_file_write(const char* p_file_name,
                     const uint8_t* p_buf,
                     size_t size);
struct util_file_map* util_file_map(const char* p_file_name,
                                    size_t max_size,
                                    int writeable);
void* util_file_map_get_ptr(struct util_file_map* p_map);
size_t util_file_map_get_size(struct util_file_map* p_map);
void util_file_unmap(struct util_file_map* p_map);

/* Timing. */
/* These quantities are in microseconds. */
uint64_t util_gettime_us();
void util_sleep_us(uint64_t us);

/* Channels. */
void util_get_channel_fds(int* fd1, int* fd2);

/* Options. */
int util_get_u32_option(uint32_t* p_opt_out,
                        const char* p_opt_str,
                        const char* p_opt_name);
int util_get_str_option(char** p_opt_out,
                        const char* p_opt_str,
                        const char* p_opt_name);
int util_has_option(const char* p_opt_str, const char* p_opt_name);

#endif /* BEEBJIT_UTIL_H */
