#include <xinu.h>

void P1(sid32 s1, sid32 s3);
void P2(sid32 s2, sid32 s1);
void P3(sid32 s3, sid32 s2);

process main(void)
{
    sid32 s1, s2, s3;

    s1 = semcreate(1);
    s2 = semcreate(0);
    s3 = semcreate(0);

    resume(create(P1, 1024, 20, "P1", 2, s1, s3));
    resume(create(P2, 1024, 20, "P2", 2, s2, s1));
    resume(create(P3, 1024, 26, "P3", 2, s3, s2));

    return OK;
}

void P1 (sid32 s1, sid32 s3) 
{
    while(1) 
    {
        wait(s1);
        printf("Kwak\n");
        sleepms(1000);
        signal(s2);
    }
}

void P2 (sid32 s2, sid32 s1) 
{
    while(1) 
    {
        wait(s2);
        printf("Kwik\n");
        sleepms(1000);
        signal(s3);
    }
}

void P3 (sid32 s3, sid32 s2) 
{
    while(1) 
    {
        wait(s3);
        printf("Kwek\n");
        sleepms(1000);
        signal(s1);
    }
}
