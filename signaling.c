#include <xinu.h>

void sndA(sid32 sl, sid32 s3);
void sndB(sid32 s2, sid32 sl);
void sndC(sid32 s3, sid32 s2);

process main(void)
{
    sid32 sl, s2, s3;

    sl = semcreate(1);
    s2 = semcreate(0);
    s3 = semcreate(0);

    

    resume(create(sndA, 1024, 20, "process A", 2, sl, s3));
    resume(create(sndB, 1024, 20, "process B", 2, s2, sl));
    resume(create(sndC, 1024, 26, "process C", 2, s3, s2));

    return OK;

void sndA (sid32 s1, sid32 s3) 
{
    while(1) 
    {
        wait(s1);
        printf("Irashaimase A\n");
        sleepms(1000);
        signal(s3);
    }
}

void sndB (sid32 s2, sid32 s1) 
{
    while(1) 
    {
        wait(s2);
        printf("Irashaimase B\n");
        sleepms(1000);
        signal(s1);
    }
}

void sndC (sid32 s3, sid32 s2) 
{
    while(1) 
    {
        wait(s3);
        printf("Irashaimase C\n");
        sleepms(1000);
        signal(s2);
    }
}