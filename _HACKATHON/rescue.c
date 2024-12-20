#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definitions for priority levels
#define HIGH_PRIORITY 1
#define LOW_PRIORITY 5

// Structure for Rescue Zone
typedef struct Zone {
    int id;
    int priority;
    int peopleInNeed;
    int supplies;
    struct Zone* next;
} Zone;

// Structure for Rescue Team
typedef struct Team {
    int id;
    int supplies;
    struct Team* next;
} Team;

// Structure for Rescued People Tracking
typedef struct RescueRecord {
    int personId;
    int zoneId;
    time_t rescueTime;
    struct RescueRecord* next;
} RescueRecord;

Zone* zoneHead = NULL;
Team* teamHead = NULL;
RescueRecord* recordHead = NULL;

// Functions for managing Zones
void addZone(int id, int priority, int peopleInNeed, int supplies) {
    Zone* newZone = (Zone*)malloc(sizeof(Zone));
    newZone->id = id;
    newZone->priority = priority;
    newZone->peopleInNeed = peopleInNeed;
    newZone->supplies = supplies;
    newZone->next = NULL;

    if (!zoneHead || zoneHead->priority > priority) {
        newZone->next = zoneHead;
        zoneHead = newZone;
    } else {
        Zone* temp = zoneHead;
        while (temp->next && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newZone->next = temp->next;
        temp->next = newZone;
    }
}

void displayZones() {
    Zone* temp = zoneHead;
    printf("\n--- Zones by Priority ---\n");
    while (temp) {
        printf("Zone ID: %d | Priority: %d | People in Need: %d | Supplies: %d\n",
               temp->id, temp->priority, temp->peopleInNeed, temp->supplies);
        temp = temp->next;
    }
}

// Functions for managing Teams
void addTeam(int id, int supplies) {
    Team* newTeam = (Team*)malloc(sizeof(Team));
    newTeam->id = id;
    newTeam->supplies = supplies;
    newTeam->next = teamHead;
    teamHead = newTeam;
}

void displayTeams() {
    Team* temp = teamHead;
    printf("\n--- Rescue Teams ---\n");
    while (temp) {
        printf("Team ID: %d | Supplies: %d\n", temp->id, temp->supplies);
        temp = temp->next;
    }
}

// Function to move team to a zone and handle rescue
void moveTeamToZone(int teamId, int zoneId) {
    Team* team = teamHead;
    while (team && team->id != teamId) {
        team = team->next;
    }

    Zone* zone = zoneHead;
    while (zone && zone->id != zoneId) {
        zone = zone->next;
    }

    if (!team || !zone) {
        printf("Invalid team or zone ID.\n");
        return;
    }

    // Check if team has enough supplies to enter the zone
    if (team->supplies >= 10) {  // Assume 10 units needed to enter a zone
        team->supplies -= 10;  // Deduct the entry supplies

        // Track rescued people from the zone
        while (zone->peopleInNeed > 0) {
            RescueRecord* newRecord = (RescueRecord*)malloc(sizeof(RescueRecord));
            newRecord->personId = zone->peopleInNeed;  // Assuming person ID is in descending order
            newRecord->zoneId = zone->id;
            time(&newRecord->rescueTime);
            newRecord->next = recordHead;
            recordHead = newRecord;

            zone->peopleInNeed--;
            printf("Rescued person %d from zone %d.\n", newRecord->personId, zone->id);
        }

        printf("Team %d completed rescue in zone %d.\n", teamId, zoneId);
    } else {
        printf("Team %d does not have enough supplies to enter zone %d.\n", teamId, zoneId);
    }
}

// Function to display rescued individuals
void displayRescueRecords() {
    RescueRecord* temp = recordHead;
    printf("\n--- Rescued People ---\n");
    while (temp) {
        printf("Person ID: %d | Rescued from Zone: %d | Rescue Time: %s",
               temp->personId, temp->zoneId, ctime(&temp->rescueTime));
        temp = temp->next;
    }
}

// Function to replenish team supplies
void replenishTeamSupplies(int teamId, int amount) {
    Team* team = teamHead;
    while (team && team->id != teamId) {
        team = team->next;
    }
    if (team) {
        team->supplies += amount;
        printf("Team %d's supplies replenished by %d units.\n", teamId, amount);
    } else {
        printf("Team ID %d not found.\n", teamId);
    }
}

// Interactive Menu
void menu() {
    int choice, id, priority, peopleInNeed, supplies, teamId, zoneId, amount;

    do {
        printf("\n--- Rescue Operation Menu ---\n");
        printf("1. Add Rescue Zone\n");
        printf("2. Display Zones by Priority\n");
        printf("3. Add Rescue Team\n");
        printf("4. Display Rescue Teams\n");
        printf("5. Move Team to Zone\n");
        printf("6. Replenish Team Supplies\n");
        printf("7. Display Rescue Records\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Zone ID, Priority (1-5), People in Need, and Supplies: ");
                scanf("%d %d %d %d", &id, &priority, &peopleInNeed, &supplies);
                addZone(id, priority, peopleInNeed, supplies);
                printf("Zone %d added.\n", id);
                break;

            case 2:
                displayZones();
                break;

            case 3:
                printf("Enter Team ID and Initial Supplies: ");
                scanf("%d %d", &teamId, &supplies);
                addTeam(teamId, supplies);
                printf("Team %d added.\n", teamId);
                break;

            case 4:
                displayTeams();
                break;

            case 5:
                printf("Enter Team ID and Zone ID: ");
                scanf("%d %d", &teamId, &zoneId);
                moveTeamToZone(teamId, zoneId);
                break;

            case 6:
                printf("Enter Team ID and Amount to Replenish: ");
                scanf("%d %d", &teamId, &amount);
                replenishTeamSupplies(teamId, amount);
                break;

            case 7:
                displayRescueRecords();
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}
