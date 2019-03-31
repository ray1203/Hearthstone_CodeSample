#include<stdio.h>
#include<string.h>
enum Tribe {
    none = 0,
    dragon,
    murloc,
    beast,
    devil,
    pirate,
    mech,
    totem,
    spirit
};
enum Job{
    warrior=0,
    shaman,
    mage,
    hunter,
    paladin,
    warlock,
    priest,
    druid,
    rogue
};
struct Minion {
    int Attack;
    int Health;
    int Cost;
    char name[20];
    enum Tribe tribe;
};
struct hero{
    int Health;
    enum Job job;
}hero;
void hero_heal(struct Minion caster,struct hero *target,int value){
    target->Health+=value;
    if(target->Health>30)target->Health=30;
    return;
}
void hero_damage(struct Minion caster,struct hero *target,int value){
    target->Health-=value;
    return;
}
void print_hero_health(struct hero target){
    printf("%d\n",target.Health);
    return;
}
int main(){
    struct hero Me,Opponent;
    struct Minion Flame_Imp,Pit_Lord,Antique_Healbot,Guardian_of_Kings;
    Me.Health=30;
    Me.job=warlock;
    Opponent.Health=30;
    Opponent.job=priest;
    Flame_Imp.Attack=3;
    Flame_Imp.Health=2;
    Flame_Imp.Cost=1;
    strcpy(Flame_Imp.name,"È­¿° ÀÓÇÁ");
    Flame_Imp.tribe=devil;
    Pit_Lord.Attack=5;
    Pit_Lord.Health=6;
    Pit_Lord.Cost=4;
    strcpy(Pit_Lord.name,"Áö¿ÁÀÇ ±ºÁÖ");
    Pit_Lord.tribe=devil;
    Antique_Healbot.Attack=3;
    Antique_Healbot.Health=3;
    Antique_Healbot.Cost=5;
    strcpy(Antique_Healbot.name,"³°Àº Ä¡À¯·Îº¿");
    Antique_Healbot.tribe=mech;
    Guardian_of_Kings.Attack=5;
    Guardian_of_Kings.Health=6;
    Guardian_of_Kings.Cost=7;
    strcpy(Guardian_of_Kings.name,"¿ÕÀÇ ¼öÈ£ÀÚ");
    Guardian_of_Kings.tribe=none;


    hero_damage(Flame_Imp,&Me,3);
    print_hero_health(Me);
    hero_damage(Pit_Lord,&Me,5);
    print_hero_health(Me);
    hero_heal(Guardian_of_Kings,&Me,6);
    print_hero_health(Me);
    hero_heal(Antique_Healbot,&Me,8);
    print_hero_health(Me);


}
