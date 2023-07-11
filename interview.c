// Mistakes - need to understand problem first -> draw out examples!
// Get the examples up on screen so other person can see it!
// Issue with alignment - alignment is relative to memory address!
// Don't talk too much - give yourself 2 minutes to just think

void* align_malloc(int num_bytes, int alignment){
    // make padding the big enough to encompass an int
    // padding != alignment, padding + padding_size = alignment
    int prefix_size = 0;
    if (alignment != 0) prefix_size = alignment*5; // guarantees prefix has size >=4 aligned by align*4 then aligned by align
    void* block = malloc(prefix_size+num_bytes);
    int padding = (int)(block)%alignment;
    void* first_aligned_start = block+padding;
    void* user_start = first_aligned_start+alignment*4;
    void** ptr_to_block = user_start-sizeof(void*);
    *ptr_to_block = block;
    return user_start;
}

void align_free(void* ptr){
    // assume we have an aligned_ptr/block
    void** ptr_to_start = ptr-sizeof(void**);
    free(*ptr_to_start);
}