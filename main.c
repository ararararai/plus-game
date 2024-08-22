#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS_SIZE 3
#define MIN 3
#define MAX 10

struct Game {
    int nums[NUMS_SIZE];
    int hope_answer;
};

void init(struct Game *game) {
    game->hope_answer = 0;
    for (int i = 0; i < NUMS_SIZE; i++) {
        game->nums[i] = (rand() % (MAX - MIN)) + MIN;
        game->hope_answer += game->nums[i];
    }
}

void draw_nums(const struct Game *game) {
    for (int i = 0; i < NUMS_SIZE; i++) {
        printf("[ %d ]", game->nums[i]);
    }
    printf("\n\n");
}

int update(struct Game *game) {
    int ans;
    printf("すべての数を足してください\n");
    draw_nums(game);
    printf("答え > ");
    if (scanf("%d", &ans) != 1) {
        while (getchar() != '\n');
        ans = -1;
    }

    if (ans == 0) {
        printf("ゲームを終了します\n");
        return 0;
    } else if (ans == game->hope_answer) {
        printf("正解\n");
    } else {
        printf("はずれ、正解は%d\n", game->hope_answer);
    }
    init(game);
    return 1;
}

int main() {
    struct Game game;
    srand(time(NULL));
    init(&game);

    while (update(&game));

    return 0;
}