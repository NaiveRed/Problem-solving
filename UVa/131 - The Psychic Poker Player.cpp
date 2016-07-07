#include<cstdio>

char card[10][3];
bool used[5], all[4][14];
int cardNum[14], best;
void choose(int n);
int countScore();
inline int toNum(char c)
{
    if (c == 'T')
        return 10;
    else if (c == 'J')
        return 11;
    else if (c == 'Q')
        return 12;
    else if (c == 'K')
        return 13;
    else if (c == 'A')
        return 1;
    else return c - '0';
}
inline int toColor(char c)
{
    if (c == 'C')
        return 0;
    else if (c == 'D')
        return 1;
    else if (c == 'H')
        return 2;
    else if (c == 'S')
        return 3;
}
int main()
{
    const char *kind[9] = { "straight-flush", "four-of-a-kind", "full-house", "flush", "straight", "three-of-a-kind", "two-pairs", "one-pair", "highest-card" };

    while (scanf("%s", card[0]) != EOF)
    {
        int i;
        for (i = 1; i < 10; i++)
            scanf("%s", card[i]);
        best = 8;
        choose(0);
        
        printf("Hand: ");
        for (i = 0; i < 5; i++)
            printf("%s ", card[i]);
        printf("Deck: ");
        for (i = 5; i < 10; i++)
            printf("%s ", card[i]);
        printf("Best hand: ");
        puts(kind[best]);
    }

    return 0;
}
void choose(int n)
{
    if (!best)
        return;

    int i;
    if (n == 5)
    {
        int count = 0, num, color;
        for (i = 0; i < 5; i++)
            if (used[i])
            {
            num = toNum(card[i][0]);
            color = toColor(card[i][1]);
            cardNum[num]++;
            all[color][num] = true;
            count++;
            }

        for (i = 5; count < 5; count++, i++)
        {
            num = toNum(card[i][0]);
            color = toColor(card[i][1]);
            cardNum[num]++;
            all[color][num] = true;
        }

        int score = countScore();
        if (best > score)
            best = score;

        //init
        for (i = 0; i < 4; i++)
            for (int j = 0; j < 14; j++)
                all[i][j] = false;
        for (i = 0; i < 14; i++)
            cardNum[i] = 0;
    }
    else
        for (i = n; i < 5; i++)
        {
        used[i] = true;
        choose(n + 1);
        used[i] = false;
        choose(n + 1);
        }

}
int countScore()
{
    //one = 7,two = 6,three = 5,house = 2,four = 1
    int best = 8, pair = 0, three = 0, i;
    for (i = 1; i <= 13; i++)
    {
        if (cardNum[i] == 4)
        {
            best = 1;
            break;
        }
        else if (cardNum[i] == 3)
            three = 1;
        else if (cardNum[i] == 2)
            pair++;
    }

    if (three&&pair)
        best = 2;
    else if (three)
        best = 5;
    else if (pair == 2)
        best = 6;
    else if (pair == 1)
        best = 7;

    if (best < 8)
        return best;
    //straight = 4,straight flush = 0
    if (cardNum[1] && cardNum[10] && cardNum[11] && cardNum[12] && cardNum[13])
    {
        best = 4;
        for (i = 0; i < 4; i++)
            if (all[i][1] && all[i][10] && all[i][11] && all[i][12] && all[i][13])
                best = 0;
    }
    for (i = 1; i <= 9 && best; i++)
        if (cardNum[i] && cardNum[i + 1] && cardNum[i + 2] && cardNum[i + 3] && cardNum[i + 4])
        {
        best = 4;
        for (int j = 0; j < 4; j++)
            if (all[j][i] && all[j][i+1] && all[j][i+2] && all[j][i+2] && all[j][i+4])
                best = 0;
        }
    
    if (best < 8)
        return best;

    //flush = 3
    int count=0;
    for (i = 0; i < 4; i++, count = 0)
    {
        for (int j = 1; j <= 13; j++)
            if (all[i][j])
                count++;
        if (count == 5)
            return 3;
    }

    return 8;
}