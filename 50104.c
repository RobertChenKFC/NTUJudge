#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member_ {
  char name[40];
  struct member_ *left;
  struct member_ *right;
};
typedef struct member_ Member;

struct club_ {
  char name[40];
  struct club_ *left;
  struct club_ *right;
  Member *member;
};
typedef struct club_ Club;

void InsertMember(Member *member, char *name, int new) {
  if (new) {
    strcpy(member->name, name); 
    return;
  } 
  int cmp = strcmp(name, member->name);
  if (cmp < 0) {
    if (member->left == NULL) {
      member->left = malloc(sizeof(Member));
      InsertMember(member->left, name, 1);
    } else {
      InsertMember(member->left, name, 0);
    }
  } else if (cmp > 0) {
    if (member->right == NULL) {
      member->right = malloc(sizeof(Member));
      InsertMember(member->right, name, 1);
    } else {
      InsertMember(member->right, name, 0);
    }
  }
}

void InsertClub(Club *club, char *clubName, char *name, int new) {
  if (new) {
    strcpy(club->name, clubName);
    club->member = malloc(sizeof(Member));
    InsertMember(club->member, name, 1);
    return;
  }
  int cmp = strcmp(clubName, club->name);
  if (cmp < 0) {
    if (club->left == NULL) {
      club->left = malloc(sizeof(Club));  
      InsertClub(club->left, clubName, name, 1); 
    } else {
      InsertClub(club->left, clubName, name, 0); 
    }
  } else if (cmp > 0) {
    if (club->right == NULL) {
      club->right = malloc(sizeof(Club));
      InsertClub(club->right, clubName, name, 1);
    } else {
      InsertClub(club->right, clubName, name, 0);
    }
  } else {
    InsertMember(club->member, name, 0); 
  }
}

char NONE[] = "None";
char* ClubLeader(Club *club, char *clubName) {
  if  (club == NULL) return NONE;
  int cmp = strcmp(clubName, club->name);
  if (cmp < 0) return ClubLeader(club->left, clubName);
  if (cmp > 0) return ClubLeader(club->right, clubName);
  return club->member->name;
}

Club* ClubPos(Club *club, char *clubName) {
  if (club == NULL) return NULL;
  int cmp = strcmp(clubName, club->name);
  if (cmp < 0) return ClubPos(club->left, clubName);
  if (cmp > 0) return ClubPos(club->right, clubName);
  return club;
}

int IsMember(Member *member, char *name) {
  if (member == NULL) return 0;
  int cmp = strcmp(name, member->name);
  if (cmp < 0) return IsMember(member->left, name);
  if (cmp > 0) return IsMember(member->right, name);
  return 1;
}

int main() {
  int state;
  char name[40];
  char clubName[40];
  Club *club = malloc(sizeof(Club));

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%s%s", &state, name, clubName);  
    InsertClub(club, clubName, name, i == 0);
  }

  scanf("%d", &n);
  while (n--) {
    scanf("%d", &state); 
    if (state == 0) {
      scanf("%s", clubName);
      printf("%s\n", ClubLeader(club, clubName));
    } else {
      scanf("%s%s", name, clubName); 
      Club *clubPos = ClubPos(club, clubName);
      if (clubPos == 0) 
        printf("-1\n");
      else if (IsMember(clubPos->member, name))
        printf("1\n");
      else
        printf("0\n");
    }
  }
}
