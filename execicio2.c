#include <stdio.h>

struct Player {
    char name[30];
    char position;
    double strength;
};

struct Team {
    char name[30];
    struct Player players[11];
};

double calculateTeamStrength(struct Team team) {
    double totalStrength = 0;

    for (int i = 0; i < 11; i++) {
        char position = team.players[i].position;
        double strength = team.players[i].strength;

        if (position == 'G') {
            totalStrength += 8.0 * strength;
        } else if (position == 'L') {
            totalStrength += 10.0 * strength;
        } else if (position == 'Z') {
            totalStrength += 5.0 * strength;
        } else if (position == 'V') {
            totalStrength += 8.0 * strength;
        } else if (position == 'M') {
            totalStrength += 11.0 * strength;
        } else if (position == 'A') {
            totalStrength += 12.0 * strength;
        }
    }

    return totalStrength / 100.0;
}

int main() {
    struct Team team1, team2;

    // Team 1
    scanf("%29[^\n]%*c", team1.name);
    for (int i = 0; i < 11; i++) {
        scanf("%29[^;]; %c; %lf%*c", team1.players[i].name, &team1.players[i].position, &team1.players[i].strength);
    }

    // Team 2
    scanf("%29[^\n]%*c", team2.name);
    for (int i = 0; i < 11; i++) {
        scanf("%29[^;]; %c; %lf%*c", team2.players[i].name, &team2.players[i].position, &team2.players[i].strength);
    }

    double strengthTeam1 = calculateTeamStrength(team1);
    double strengthTeam2 = calculateTeamStrength(team2);

    printf("%s: %.2lf strength\n", team1.name, strengthTeam1);
    printf("%s: %.2lf strength\n", team2.name, strengthTeam2);

    if (strengthTeam1 > strengthTeam2) {
        printf("%s is stronger\n", team1.name);
    } else if (strengthTeam2 > strengthTeam1) {
        printf("%s is stronger\n", team2.name);
    } else {
        printf("The teams have the same strength: %.2lf\n", strengthTeam1);
    }

    return 0;
}
