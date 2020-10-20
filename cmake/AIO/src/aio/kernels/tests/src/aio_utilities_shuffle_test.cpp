/* header files */
#include "aio_utilities_shuffle_test.h"

void aio_utilities_testcheck(){
    printf("Starting AIO utilities tests...\n");
}

static
char shuffle_test(unsigned int nsamples,unsigned int shuffle,unsigned int seed, char display){
    long unsigned int memory_allocated;
    unsigned int i;
    unsigned int *vec, *vec_check;

    Real shuffle_time;
    Real memory1, memory2;
    int rank = 0;

    memory1 = memory_usage(rank,display);
    memory_allocated = nsamples * sizeof(unsigned int);
    printf("   [Shuffle] Number of Samples: %'u (Mem: %1.2e GB)\n", nsamples, B2GB(memory_allocated));
    printf("   [Shuffle] Test Memory Allocating: %1.2e GB\n", B2GB(2*memory_allocated));

    /* allocate vec_check */
    vec_check = (unsigned int *) malloc(nsamples * sizeof(unsigned int));
    for(i = 0; i < nsamples; ++i) vec_check[i] = 0;

    printf("   [Shuffle] Begin Shuffle ..."); fflush(stdout);
    /* ---------------------------------------------------------------------- */
    /* shuffle function */
    TIMER(
        vec = aio_utilities_shuffle(nsamples,shuffle,seed), // function
        shuffle_time                                 // wall-clock time
    );
    /* ---------------------------------------------------------------------- */
    printf(" Done\n");
    printf("   [Shuffle] Time: %.6f sec, Time/sample: %.4e sec\n",
            shuffle_time,shuffle_time / (Real) nsamples);

    if (display) printArray1D_UnsigedInt(vec,nsamples);

    /* check vec to ensure all values remain but shuffled */
    printf("   [Shuffle] Checking Shuffle ..."); fflush(stdout);
    for(i = 0; i < nsamples; ++i) vec_check[vec[i]] = 1;
    for(i = 0; i < nsamples; ++i) EXPECT_EQUAL_TEST(vec_check[i], 1);
    printf(" Done\n");

    /* deallocate memory */
    if(vec) free(vec); vec = NULL;
    if(vec_check) free(vec_check); vec_check = NULL;
    memory2 = memory_usage(rank,display);
    return EXIT_SUCCESS;
}

TEST(AIO_UTILITIES,shuffle){
    unsigned int nsamples = 1000000;
    unsigned int shuffle = 1;
    unsigned int seed = (unsigned int) time(NULL);
    char display = 0;

    shuffle_test(nsamples,shuffle,seed,display);
}