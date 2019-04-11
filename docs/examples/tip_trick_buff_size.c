/* Number of data blocks to write */
#define N          3

/* Create custom data structure */
/* Data is array of 2 32-bit words, 8-bytes */
uint32_t d[2];

/* Create buffer structures */
ringbuff_t buff_1;
ringbuff_t buff_2;

/* Create data for buffers. Use sizeof structure, multiplied by N (for N instances) */
/* Add + 1 at the end to make buffer `1` byte bigger */
uint8_t buff_data_1[sizeof(d) * N + 1];
/* Use second buffer without + 1 at the end */
uint8_t buff_data_2[sizeof(d) * N];

/* Write result values */
size_t len_1;
size_t len_2;

/* Initialize buffer */
ringbuff_init(&buff_1, buff_data_1, sizeof(buff_data_1));
ringbuff_init(&buff_2, buff_data_2, sizeof(buff_data_2));

/* Now uses buffer to write data */
for (size_t i = 0; i < N; i++) {
    /* Prepare dummy data */
    d.a = i;
    d.b = i * 2;

    /* Write data to both buffers */
    /* Copy content from d to buffer */
    len_1 = ringbuff_write(&buff_1, d, sizeof(d));
    len_2 = ringbuff_write(&buff_2, d, sizeof(d));

    /* Print result */
    printf("Write buffer 1: %d/%d bytes; buffer 2: %d/%d\r\n",
        (int)len_1, (int)sizeof(d),
        (int)len_2, (int)sizeof(d));
}