#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

const int N = 50;

int n, sol[N], solNumCnt[6], seqNumCnt[6], diffCnt[N], seq[N];

FILE* output = fopen("output.txt", "w");
FILE* seqoutput = fopen("seq.txt", "w");


int chkDiff()
{
	int diff = 0;
	for (int i = 1; i <= n; i++)
	{
		if (seq[i] != sol[i])
			diff++;
	}
	return diff;
}

int createSeq(int depth)
{
	if (depth == n)
	{
		diffCnt[chkDiff()]++;
		for (int i = 1; i <= n; i++)
		{
			fprintf(seqoutput, "%d", seq[i]);
		}
		fprintf(seqoutput, "\n");
		return 0;
	}
	for (int i = 1; i <= 5; i++)
	{
		if (seqNumCnt[i] + 1 > solNumCnt[i])
			continue;
		seqNumCnt[i]++;
		seq[depth + 1] = i;
		createSeq(depth + 1);
		seqNumCnt[i]--;
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%1d", &sol[i]);
		solNumCnt[sol[i]]++;
	}
	createSeq(0);
	for (int i = 0; i <= n; i++)
	{
		fprintf(output, "diffCnt[ %d ] : %d \n", i, diffCnt[i]);
		//printf("diffCnt[ %d ] : %d \n", i, diffCnt[i]);
	}
	fclose(output);
	fclose(seqoutput);
	return 0;
}