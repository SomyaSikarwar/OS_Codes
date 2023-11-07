#include <stdio.h>

struct Process {
    int id;
    int at;
    int bt;
    int wt;
    int tat;
};

void del(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i] = p[i + 1];
    }
}

void sort(struct Process p[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (p[j].bt > p[j + 1].bt) {
                struct Process t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
}

void SJFScheduling(struct Process p[], int n) {
    int total = 0;
    int i = 0;
    int pos = 0;
    int count = 0;
    struct Process ep[10], exe;

    ep[pos++] = p[i++];
    total = ep[0].bt;

    for (int j = 0; j <= total; j++) {
        exe = ep[0];
        exe.bt = exe.bt - 1;
        count++;

        ep[0] = exe;

        if (exe.bt == 0) {
            ep[0] = exe;

            for (int t = 0; t < n; t++) {
                if (exe.id == p[t].id) {
                    int temp = p[t].bt; // temp to recover bt
                    p[t] = exe;         // this line will assign bt = 0 as exe.bt = 0
                    p[t].bt = temp;
                    p[t].wt = count - p[t].bt - p[t].at;
                    p[t].tat = p[t].wt + p[t].bt;
                }
            }

            printf("process %d ended at : %d\n", exe.id, count);
            del(ep, pos);
            pos--;
        }

        if (i < n && p[i].at <= count) {
            for (int x = i; x < n; x++) {
                if (p[x].at <= count) {
                    ep[pos++] = p[i++];
                    total += p[x].bt;
                }
            }
            sort(ep, pos);
        }
    }

    printf("pid\tat\tbt\twt\ttat\n");
    float avgWt = 0;
    float avgTat = 0;

    for (int j = 0; j < n; j++) {
        struct Process pr = p[j];
        printf("%d\t%d\t%d\t%d\t%d\n", pr.id, pr.at, pr.bt, pr.wt, pr.tat);
        avgWt += pr.wt;
        avgTat += pr.tat;
    }

    avgWt = avgWt / n;
    avgTat = avgTat / n;
    printf("average waiting time : %f\n", avgWt);
    printf("average turn around time : %f\n", avgTat);
}

int main() {
    int n;
    struct Process p[10];

    printf("enter number of processes\n");
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
        p[j].id = j + 1;
        printf("enter arrival time of process %d\n", j + 1);
        scanf("%d", &p[j].at);
        printf("enter burst time of process %d\n", j + 1);
        scanf("%d", &p[j].bt);
    }

    SJFScheduling(p, n);

    return 0;
}
