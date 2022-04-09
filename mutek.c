#include <xinu.h>

void prosedur(sid32, sid32, sid32);
void konsumer(sid32, sid32, sid32;

int32 n = 1;

process main(void)
{
    sid32 mutex, sem1, sem2;

    mutex = semcreate(1);
    sem1 = semcreate(1);
    sem2 = semcreate(0);

    resume(create(P1, 1024, 20, "produser", 1, mutex, sem1, sem2));
    resume(create(P2, 1024, 20, "konsumer", 1, mutex, sem1, sem2));

    return OK;
}

void produser (sid32 mutex, sid32 sem1, sid32 sem2) 
{
    int32 i;
    for (i = 0; i < 1000; i++)
    {
        wait(sem1);
        wait(mutex);
        n++;
        printf("Produser memproduksi nilai %d\n", n);
        signal(mutex);
        signal(sem2);
    }
    
}

void konsumer (sid32 mutex, sid32 sem1, sid32 sem2) 
{
    int32 i;
    for (i = 0; i < 1000; i++)
    {
        wait(sem2);
        wait(mutex);
        printf("Konsumer menampilkan nilai %d\n", n);
        signal(mutex);
        signal(sem1);
    }
    
}

