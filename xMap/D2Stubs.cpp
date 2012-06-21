#include "xMap.h"

int AreaLocaleId[] = { 0, 5055, 5054, 5053, 5052, 5051, 5050, 5049, 3714, 5047, 5046, 5045, 5044, 5043, 5042, 5041, 5040, 5039, 5038, 5037, 5036, 5035, 5034, 5033, 5032, 5031, 5030, 5029, 5028, 5027, 5026, 5025, 5024, 5023, 5022, 5021, 5020, 5019, 5018, 788, 852, 851, 850, 849, 848, 847, 846, 845, 844, 843, 842, 841, 840, 839, 838, 837, 836, 835, 834, 833, 832, 831, 830, 829, 828, 827, 826, 826, 826, 826, 826, 826, 826, 825, 824, 820, 819, 818, 817, 816, 815, 814, 813, 812, 810, 811, 809, 808, 806, 805, 807, 804, 845, 844, 803, 802, 801, 800, 799, 798, 797, 796, 795, 790, 792, 793, 794, 791, 789, 22646, 22647, 22648, 22649, 22650, 22651, 22652, 22653, 22654, 22655, 22656, 22657, 22660, 21865, 21866, 21867, 22658, 22659, 22662, 22663, 22664, 22665, 22667, 22666, 11155, 11156, 11157, 5018 };

enum UIVar
{
    UIVAR_UNK0          = 0x00, // always 1
    UIVAR_INVENTORY     = 0x01, // hotkey 'B'
    UIVAR_STATS         = 0x02, // hotkey 'C'
    UIVAR_CURRSKILL     = 0x03, // left or right hand skill selection
    UIVAR_SKILLS        = 0x04, // hotkey 'T'
    UIVAR_CHATINPUT     = 0x05, // chat with other players, hotkey ENTER
    UIVAR_NEWSTATS      = 0x06, // new stats button
    UIVAR_NEWSKILL      = 0x07, // new skills button
    UIVAR_INTERACT      = 0x08, // interact with NPC
    UIVAR_GAMEMENU      = 0x09, // hotkey ESC
    UIVAR_AUTOMAP       = 0x0A, // hotkey TAB
    UIVAR_CFGCTRLS      = 0x0B, // config control key combination
    UIVAR_NPCTRADE      = 0x0C, // trade, game, repair with NPC
    UIVAR_SHOWITEMS     = 0x0D, // hotkey ALT
    UIVAR_MODITEM       = 0x0E, // add socket, imbue item
    UIVAR_QUEST         = 0x0F, // hotkey 'Q'
    UIVAR_UNK16         = 0x10,
    UIVAR_QUESTLOG      = 0x11, // quest log button on the bottom left screen
    UIVAR_STATUSAREA    = 0x12, // lower panel can not redraw when set
    UIVAR_UNK19         = 0x13, // init 1
    UIVAR_WAYPOINT      = 0x14,
    UIVAR_MINIPANEL     = 0x15,
    UIVAR_PARTY         = 0x16, // hotkey 'P'
    UIVAR_PPLTRADE      = 0x17, // trade, exchange items with other player
    UIVAR_MSGLOG        = 0x18,
    UIVAR_STASH         = 0x19,
    UIVAR_CUBE          = 0x1A,
    UIVAR_UNK27         = 0x1B,
    UIVAR_INVENTORY2    = 0x1C,
    UIVAR_INVENTORY3    = 0x1D,
    UIVAR_INVENTORY4    = 0x1E,
    UIVAR_BELT          = 0x1F,
    UIVAR_UNK32         = 0x20,
    UIVAR_HELP          = 0x21, // help scrren, hotkey 'H'
    UIVAR_UNK34         = 0x22,
    UIVAR_UNK35         = 0x23, // init 1
    UIVAR_PET           = 0x24, // hotkey 'O'
    UIVAR_QUESTSCROLL   = 0x25, // for showing quest information when click quest item.
};

#pragma region MonsterColors
INT nMonsterColors[1000] = {
    -1,     //  0 Skeleton
    -1,     //  1 Returned
    -1,     //  2 BoneWarrior
    -1,     //  3 BurningDead
    -1,     //  4 Horror
    -1,     //  5 Zombie
    -1,     //  6 HungryDead
    -1,     //  7 Ghoul
    -1,     //  8 DrownedCarcass
    -1,     //  9 PlagueBearer
    -1,     //  10 Afflicted
    -1,     //  11 Tainted
    -1,     //  12 Misshapen
    -1,     //  13 Disfigured
    -1,     //  14 Damned
    -1,     //  15 FoulCrow
    -1,     //  16 BloodHawk
    -1,     //  17 BlackRaptor
    -1,     //  18 CloudStalker
    -1,     //  19 Fallen
    -1,     //  20 Carver
    -1,     //  21 Devilkin
    -1,     //  22 DarkOne
    -1,     //  23 WarpedFallen
    -1,     //  24 Brute
    -1,     //  25 Yeti
    -1,     //  26 Crusher
    -1,     //  27 WailingBeast
    -1,     //  28 GargantuanBeast
    -1,     //  29 SandRaider
    -1,     //  30 Marauder
    -1,     //  31 Invader
    -1,     //  32 Infidel
    -1,     //  33 Assailant
    -1,     //  34 unused, Gorgon
    -1,     //  35 unused, StoneStalker
    -1,     //  36 unused, SerpentQueen
    -1,     //  37 unused, StygianWatcher
    -1,     //  38 Ghost
    -1,     //  39 Wraith
    -1,     //  40 Specter
    -1,     //  41 Apparition
    -1,     //  42 DarkShape
    -1,     //  43 DarkHunter
    -1,     //  44 VileHunter
    -1,     //  45 DarkStalker
    -1,     //  46 BlackRogue
    -1,     //  47 FleshHunter
    -1,     //  48 DuneBeast
    -1,     //  49 RockDweller
    -1,     //  50 JungleHunter
    -1,     //  51 DoomApe
    -1,     //  52 TempleGuard
    -1,     //  53 MoonClan
    -1,     //  54 NightClan
    -1,     //  55 BloodClan
    -1,     //  56 HellClan
    -1,     //  57 DeathClan
    -1,     //  58 FallenShaman
    -1,     //  59 CarverShaman
    -1,     //  60 DevilkinShaman
    -1,     //  61 DarkShaman
    -1,     //  62 WarpedShaman
    -1,     //  63 QuillRat
    -1,     //  64 SpikeFiend
    -1,     //  65 ThornBeast
    -1,     //  66 RazorSpine
    -1,     //  67 JungleUrchin
    -1,     //  68 SandMaggot
    -1,     //  69 RockWorm
    -1,     //  70 Devourer
    -1,     //  71 GiantLamprey
    -1,     //  72 WorldKiller
    -1,     //  73 TombViper
    -1,     //  74 ClawViper
    -1,     //  75 Salamander
    -1,     //  76 PitViper
    -1,     //  77 SerpentMagus
    -1,     //  78 SandLeaper
    -1,     //  79 CaveLeaper
    -1,     //  80 TombCreeper
    -1,     //  81 TreeLurker
    -1,     //  82 RazorPitDemon
    -1,     //  83 Huntress
    -1,     //  84 SaberCat
    -1,     //  85 NightTiger
    -1,     //  86 HellCat
    -1,     //  87 Itchies
    -1,     //  88 BlackLocusts
    -1,     //  89 PlagueBugs
    -1,     //  90 HellSwarm
    -1,     //  91 DungSoldier
    -1,     //  92 SandWarrior
    -1,     //  93 Scarab
    -1,     //  94 SteelWeevil
    -1,     //  95 AlbinoRoach
    -1,     //  96 DriedCorpse
    -1,     //  97 Decayed
    -1,     //  98 Embalmed
    -1,     //  99 PreservedDead
    -1,     //  100 Cadaver
    -1,     //  101 HollowOne
    -1,     //  102 Guardian
    -1,     //  103 Unraveler
    -1,     //  104 Horadrim Ancient
    -1,     //  105 Baal Subject Mummy
    -1,     //  106 unused, DamnedHorde
    -1,     //  107 unused, TwistedHorde
    -1,     //  108 unused, WickedHorde
    -1,     //  109 unused, UnholyHorde
    -1,     //  110 CarrionBird
    -1,     //  111 UndeadScavenger
    -1,     //  112 HellBuzzard
    -1,     //  113 WingedNightmare
    -1,     //  114 Sucker
    -1,     //  115 Feeder
    -1,     //  116 BloodHook
    -1,     //  117 BloodWing
    -1,     //  118 Gloam
    -1,     //  119 SwampGhost
    -1,     //  120 BurningSoul
    -1,     //  121 BlackSoul
    -1,     //  122 Arach
    -1,     //  123 SandFisher
    -1,     //  124 PoisonSpinner
    -1,     //  125 FlameSpider
    -1,     //  126 SpiderMagus
    -1,     //  127 ThornedHulk
    -1,     //  128 BrambleHulk
    -1,     //  129 Thrasher
    -1,     //  130 Spikefist
    -1,     //  131 GhoulLord
    -1,     //  132 NightLord
    -1,     //  133 DarkLord
    -1,     //  134 BloodLord
    -1,     //  135 Banished
    -1,     //  136 DesertWing
    -1,     //  137 Fiend
    -1,     //  138 Gloombat
    -1,     //  139 BloodDiver
    -1,     //  140 DarkFamiliar
    -1,     //  141 RatMan
    -1,     //  142 Fetish
    -1,     //  143 Flayer
    -1,     //  144 SoulKiller
    -1,     //  145 StygianDoll
    -2,     //  146 DeckardCain
    -2,     //  147 Gheed
    -2,     //  148 Akara
    -2,     //  149 dummy, chicken
    -2,     //  150 Kashya
    -2,     //  151 dummy, rat
    -2,     //  152 Dummy, RogueTown
    -2,     //  153 Dummy, HellMeteor
    -2,     //  154 Charsi
    -2,     //  155 Warriv
    -1,     //  156 Andariel
    -2,     //  157 dummy, Smallbird
    -2,     //  158 dummy, Largebird
    -2,     //  159 dummy, Bat
    -1,     //  160 DarkRanger
    -1,     //  161 VileArcher
    -1,     //  162 DarkArcher
    -1,     //  163 BlackArcher
    -1,     //  164 FleshArcher
    -1,     //  165 DarkSpearwoman
    -1,     //  166 VileLancer
    -1,     //  167 DarkLancer
    -1,     //  168 BlackLancer
    -1,     //  169 FleshLancer
    -1,     //  170 SkeletonArcher
    -1,     //  171 ReturnedArcher
    -1,     //  172 BoneArcher
    -1,     //  173 BurningDeadArcher
    -1,     //  174 HorrorArcher
    -2,     //  175 Warriv
    -2,     //  176 Atma
    -2,     //  177 Drognan
    -2,     //  178 Fara
    -2,     //  179 dummy, Cow
    -1,     //  180 SandMaggotYoung
    -1,     //  181 RockWormYoung
    -1,     //  182 DevourerYoung
    -1,     //  183 GiantLampreyYoung
    -1,     //  184 WorldKillerYoung
    -2,     //  185 dummy, Camel
    -1,     //  186 Blunderbore
    -1,     //  187 Gorbelly
    -1,     //  188 Mauler
    -1,     //  189 Urdar
    -1,     //  190 SandMaggotEgg
    -1,     //  191 RockWormEgg
    -1,     //  192 DevourerEgg
    -1,     //  193 GiantLampreyEgg
    -1,     //  194 WorldKillerEgg
    -2,     //  195 dummy, Act2Male
    -2,     //  196 Dummy, Act2Female
    -2,     //  197 dummy, Act2Child
    -2,     //  198 Greiz
    -2,     //  199 Elzix
    -2,     //  200 Geglash
    -2,     //  201 Jerhyn
    -2,     //  202 Lysander
    -2,     //  203 Dummy, Act2Guard
    -2,     //  204 dummy, Act2Vendor1
    -2,     //  205 dummy, Act2Vendor2
    -1,     //  206 FoulCrowNest
    -1,     //  207 BloodHawkNest
    -1,     //  208 BlackVultureNest
    -1,     //  209 CloudStalkerNest
    -2,     //  210 Meshif
    -1,     //  211 Duriel
    -1,     //  212 Undead RatMan
    -1,     //  213 Undead Fetish
    -1,     //  214 Undead Flayer
    -1,     //  215 Undead SoulKiller
    -1,     //  216 Undead StygianDoll
    -1,     //  217 unused, DarkGuard
    -1,     //  218 unused, DarkKnight
    -1,     //  219 unused, BloodGuard
    -1,     //  220 unused, BloodKnight
    -1,     //  221 unused, DarkPaladin
    -1,     //  222 unused, BloodMage
    -1,     //  223 unused, Demonist
    -1,     //  224 unused, BlackMagus
    -1,     //  225 unused, Diabolist
    -1,     //  226 unused, DeathMage
    -2,     //  227 Maggot
    -1,     //  228 MummyGenerator
    -1,     //  229 Radament
    -1,     //  230 unused, FireBeast
    -1,     //  231 unused, IceGlobe
    -1,     //  232 unused, LightningBeast
    -1,     //  233 unused, PoisonOrb
    -1,     //  234 FlyingScimitar
    -1,     //  235 Zakarumite
    -1,     //  236 Faithful
    -1,     //  237 Zealot
    -1,     //  238 Sexton
    -1,     //  239 Cantor
    -1,     //  240 Heirophant
    -1,     //  241 Heirophant
    -1,     //  242 Mephisto
    -1,     //  243 Diablo
    -2,     //  244 DeckardCain
    -2,     //  245 DeckardCain
    -2,     //  246 DeckardCain
    -1,     //  247 Swamp Dweller
    -1,     //  248 Bog Creature
    -1,     //  249 Slime Prince
    -1,     //  250 Summoner
    -2,     //  251 tyrael
    -2,     //  252 asheara
    -2,     //  253 hratli
    -2,     //  254 alkor
    -2,     //  255 ormus
    -1,     //  256 izual
    -2,     //  257 halbu
    -1,     //  258 WaterWatcherLimb
    -1,     //  259 RiverStalkerLimb
    -1,     //  260 StygianWatcherLimb
    -1,     //  261 WaterWatcherHead
    -1,     //  262 RiverStalkerHead
    -1,     //  263 StygianWatcherHead
    -2,     //  264 meshif
    -2,     //  265 DeckardCain
    -2,     //  266 navi (flavie)
    -1,     //  267 Bloodraven
    -2,     //  268 Dummy, bug
    -2,     //  269 Dummy, scorpion
    -1,     //  270 RogueScout
    -2,     //  271 Dummy, RogueHireling (act1 hireling)
    -2,     //  272 Dummy, RogueTownShoot
    -1,     //  273 GargoyleTrap
    -1,     //  274 ReturnedMage
    -1,     //  275 BoneMage
    -1,     //  276 BurningDeadMage
    -1,     //  277 HorrorMage
    -1,     //  278 RatManShaman
    -1,     //  279 FetishShaman
    -1,     //  280 FlayerShaman
    -1,     //  281 SoulKillerShaman
    -1,     //  282 StygianDollShaman
    -2,     //  283 larva
    -1,     //  284 SandMaggotQueen
    -1,     //  285 RockWormQueen
    -1,     //  286 DevourerQueen
    -1,     //  287 GiantLampreyQueen
    -1,     //  288 WorldKillerQueen
    -2,     //  289 ClayGolem
    -2,     //  290 BloodGolem
    -2,     //  291 IronGolem
    -2,     //  292 FireGolem
    -2,     //  293 Dummy, Familiar
    -2,     //  294 Dummy, Act3Male
    -1,     //  295 NightMarauder
    -2,     //  296 Dummy, Act3Female
    -2,     //  297 Natalya
    -1,     //  298 FleshSpawner
    -1,     //  299 StygianHag
    -1,     //  300 Grotesque
    -1,     //  301 FleshBeast
    -1,     //  302 StygianDog
    -1,     //  303 GrotesqueWyrm
    -1,     //  304 Groper
    -1,     //  305 Strangler
    -1,     //  306 StormCaster
    -1,     //  307 Corpulent
    -1,     //  308 CorpseSpitter
    -1,     //  309 MawFiend
    -1,     //  310 DoomKnight
    -1,     //  311 AbyssKnight
    -1,     //  312 OblivionKnight
    -1,     //  313 QuillBear
    -1,     //  314 SpikeGiant
    -1,     //  315 ThornBrute
    -1,     //  316 RazorBeast
    -1,     //  317 GiantUrchin
    -2,     //  318 Dummy, Snake
    -2,     //  319 Dummy, Parrot
    -2,     //  320 Dummy, Fish
    -2,     //  321 Dummy, Evil Hole
    -2,     //  322 Dummy, Evil Hole
    -2,     //  323 Dummy, Evil Hole
    -2,     //  324 Dummy, Evil Hole
    -2,     //  325 Dummy, Evil Hole
    -2,     //  326 a trap, trapfirebolt
    -2,     //  327 a trap
    -2,     //  328 a trap (act2 wall, act3 totem)
    -2,     //  329 a trap, trappoison
    -2,     //  330 a trap, trapchainlightning
    -2,     //  331 Kaelan
    -2,     //  332 Dummy, InvisoSpawner
    -1,     //  333 unused, DiabloClone
    -1,     //  334 SuckerNest
    -1,     //  335 FeederNest
    -1,     //  336 BloodHookNest
    -1,     //  337 BloodWingNest
    -2,     //  338 Guard (act2 hireling)
    -2,     //  339 Dummy, MiniSpider
    -1,     //  340 x, PrisonFL
    -1,     //  341 x, PrisonFR
    -1,     //  342 x, PrisonBL
    -1,     //  343 x, PrisonBR
    -2,     //  344 Dummy, Bonewall*
    -1,     //  345 Council Member
    -1,     //  346 Council Member
    -1,     //  347 Council Member
    -1,     //  348 Turret1
    -1,     //  349 Turret2
    -1,     //  350 Turret3
    -2,     //  351 Hydra1
    -2,     //  352 Hydra2
    -2,     //  353 Hydra3
    -1,     //  354 a trap, pillar
    -2,     //  355 Dummy, seven tombs
    -1,     //  356 Dopplezon
    -2,     //  357 Valkyrie
    -2,     //  358 Dummy, Act2Hireling
    -2,     //  359 Iron Wolf (act3 town+hireling)*
    -1,     //  360 Balrog
    -1,     //  361 PitLord
    -1,     //  362 VenomLord
    -2,     //  363 NecroSkeleton (necro skel)
    -2,     //  364 NecroMage (necro mage)
    -1,     //  365 Griswold
    -2,     //  366 compellingorb
    -2,     //  367 tyrael
    -2,     //  368 youngdiablo
    -2,     //  369 a trap, nova
    -1,     //  370 Dummy, SpiritMummy
    -1,     //  371 LightningSpire
    -1,     //  372 FireTower
    -1,     //  373 Slinger
    -1,     //  374 SpearCat
    -1,     //  375 NightSlinger
    -1,     //  376 HellSlinger
    -2,     //  377 Dummy, Boba Fett
    -2,     //  378 Dummy, Darth Maul
    -1,     //  379 ReturnedMage
    -1,     //  380 BoneMage
    -1,     //  381 BaalColdMage
    -1,     //  382 HorrorMage
    -1,     //  383 ReturnedMage
    -1,     //  384 BoneMage
    -1,     //  385 BurningDeadMage
    -1,     //  386 HorrorMage
    -1,     //  387 ReturnedMage
    -1,     //  388 BoneMage
    -1,     //  389 BurningDeadMage
    -1,     //  390 HorrorMage
    -1,     //  391 Hell Bovine
    -2,     //  392 x, window right (act4 window)*
    -2,     //  393 x, window left (act4 window)*
    -1,     //  394 SpearCat
    -1,     //  395 NightSlinger
    -1,     //  396 RatMan
    -1,     //  397 Fetish
    -1,     //  398 Flayer
    -1,     //  399 SoulKiller
    -1,     //  400 StygianDoll
    -2,     //  401 Dummy, Mephisto Spirit
    -1,     //  402 The Smith
    -2,     //  403 TrappedSoul*
    -2,     //  404 TrappedSoul*
    -2,     //  405 Jamella
    -2,     //  406 Izual's Ghost
    -1,     //  407 RatMan
    -2,     //  408 Malachai?
    -1,     //  409 The Feature Creep
    -2,     //  410 Wake of Destruction
    -2,     //  411 Charged Bolt Sentry
    -2,     //  412 Lightning Sentry
    -2,     //  413 Blade Creeper (blade sentinel)
    -2,     //  414 Invis Pet*
    -2,     //  415 Inferno Sentry
    -2,     //  416 Death Sentry
    -2,     //  417 Shadow Warrior
    -2,     //  418 Shadow Master
    -2,     //  419 Druid Hawk*
    -2,     //  420 Druid Spirit Wolf
    -2,     //  421 Druid Fenris (dire wolf)
    -2,     //  422 Spirit of Barbs
    -2,     //  423 Heart of Wolverine
    -2,     //  424 Oak Sage
    -2,     //  425 Druid Plague Poppy (poison creeper)*
    -2,     //  426 Druid Cycle of Life (carrion vine)*
    -2,     //  427 Vine Creature (solar creeper)*
    -2,     //  428 Druid Bear
    -1,     //  429 Eagle
    -1,     //  430 Wolf
    -1,     //  431 Bear
    -2,     //  432 Barricade Door*
    -2,     //  433 Barricade Door*
    -2,     //  434 Prison Door*
    -2,     //  435 Barricade Tower*
    -1,     //  436 RotWalker
    -1,     //  437 ReanimatedHorde
    -1,     //  438 ProwlingDead
    -1,     //  439 UnholyCorpse
    -1,     //  440 DefiledWarrior
    -1,     //  441 Siege Beast
    -1,     //  442 CrushBiest
    -1,     //  443 BloodBringer
    -1,     //  444 GoreBearer
    -1,     //  445 DeamonSteed
    -1,     //  446 SnowYeti1
    -1,     //  447 SnowYeti2
    -1,     //  448 SnowYeti3
    -1,     //  449 SnowYeti4
    -1,     //  450 WolfRider1
    -1,     //  451 WolfRider2
    -1,     //  452 WolfRider3
    -1,     //  453 Minionexp
    -1,     //  454 Slayerexp
    -1,     //  455 IceBoar
    -1,     //  456 FireBoar
    -1,     //  457 HellSpawn
    -1,     //  458 IceSpawn
    -1,     //  459 GreaterHellSpawn
    -1,     //  460 GreaterIceSpawn
    -1,     //  461 FanaticMinion
    -1,     //  462 BerserkSlayer
    -1,     //  463 ConsumedFireBoar
    -1,     //  464 ConsumedIceBoar
    -1,     //  465 FrenziedHellSpawn
    -1,     //  466 FrenziedIceSpawn
    -1,     //  467 InsaneHellSpawn
    -1,     //  468 InsaneIceSpawn
    -1,     //  469 Succubusexp
    -1,     //  470 VileTemptress
    -1,     //  471 StygianHarlot
    -1,     //  472 Hell Temptress
    -1,     //  473 Blood Temptress
    -1,     //  474 Dominus
    -1,     //  475 VileWitch
    -1,     //  476 StygianFury
    -1,     //  477 Blood Witch
    -1,     //  478 Hell Witch
    -1,     //  479 OverSeer
    -1,     //  480 Lasher
    -1,     //  481 OverLord
    -1,     //  482 BloodBoss
    -1,     //  483 HellWhip
    -1,     //  484 MinionSpawner
    -1,     //  485 MinionSlayerSpawner
    -1,     //  486 MinionIce/fireBoarSpawner
    -1,     //  487 MinionIce/fireBoarSpawner
    -1,     //  488 Minionice/hellSpawnSpawner
    -1,     //  489 MinionIce/fireBoarSpawner
    -1,     //  490 MinionIce/fireBoarSpawner
    -1,     //  491 Minionice/hellSpawnSpawner
    -1,     //  492 Imp1
    -1,     //  493 Imp2
    -1,     //  494 Imp3
    -1,     //  495 Imp4
    -1,     //  496 Imp5
    -1,     //  497 CatapultS
    -1,     //  498 CatapultE
    -1,     //  499 CatapultSiege
    -1,     //  500 CatapultW
    -1,     //  501 Frozen Horror1
    -1,     //  502 Frozen Horror2
    -1,     //  503 Frozen Horror3
    -1,     //  504 Frozen Horror4
    -1,     //  505 Frozen Horror5
    -1,     //  506 Blood Lord1
    -1,     //  507 Blood Lord2
    -1,     //  508 Blood Lord3
    -1,     //  509 Blood Lord4
    -1,     //  510 Blood Lord5
    -2,     //  511 Larzuk
    -2,     //  512 Drehya
    -2,     //  513 Malah
    -2,     //  514 Nihlathak Town
    -2,     //  515 Qual-Kehk
    -2,     //  516 Catapult Spotter S (target?)
    -2,     //  517 Catapult Spotter E (target?)
    -2,     //  518 Catapult Spotter Siege (target?)
    -2,     //  519 Catapult Spotter W
    -2,     //  520 DeckardCain
    -2,     //  521 Tyrael
    0xCB,   //  522 Act 5 Combatant (barb fighter)*
    -2,     //  523 Act 5 Combatant*
    -2,     //  524 Barricade Wall Right*
    -2,     //  525 Barricade Wall Left*
    -1,     //  526 Nihlathak outside town
    -2,     //  527 Drehya outside town
    -1,     //  528 Evil hut
    -1,     //  529 Death Mauler1
    -1,     //  530 Death Mauler2
    -1,     //  531 Death Mauler3
    -1,     //  532 Death Mauler4
    -1,     //  533 Death Mauler5
    -2,     //  534 POW (captured barb)*
    -2,     //  535 Act 5 Townguard
    -2,     //  536 Act 5 Townguard
    -2,     //  537 Ancient Statue 1
    -2,     //  538 Ancient Statue 2
    -2,     //  539 Ancient Statue 3
    -1,     //  540 Ancient Barbarian 1
    -1,     //  541 Ancient Barbarian 2
    -1,     //  542 Ancient Barbarian 3
    -2,     //  543 Baal Throne
    -1,     //  544 Baal Crab
    -2,     //  545 Baal Taunt (invis follower)
    -1,     //  546 Putrid Defiler1
    -1,     //  547 Putrid Defiler2
    -1,     //  548 Putrid Defiler3
    -1,     //  549 Putrid Defiler4
    -1,     //  550 Putrid Defiler5
    -1,     //  551 Pain Worm1
    -1,     //  552 Pain Worm2
    -1,     //  553 Pain Worm3
    -1,     //  554 Pain Worm4
    -1,     //  555 Pain Worm5
    -2,     //  556 Bunny
    -1,     //  557 Council Member
    -1,     //  558 VenomLord
    -2,     //  559 Baal Crab to Stairs
    -2,     //  560 Act 5 Hireling 1hs
    -2,     //  561 Act 5 Hireling 2hs (act5 hireling)
    -1,     //  562 Baal Tentacle
    -1,     //  563 Baal Tentacle
    -1,     //  564 Baal Tentacle
    -1,     //  565 Baal Tentacle
    -1,     //  566 Baal Tentacle
    -2,     //  567 Injured Barbarian 1 (town barb)
    -2,     //  568 Injured Barbarian 2 (town barb)
    -2,     //  569 Injured Barbarian 3 (town barb)
    -1,     //  570 Baal Crab Clone
    -1,     //  571 Baals Minion
    -1,     //  572 Baals Minion
    -1,     //  573 Baals Minion
    -2,     //  574 Worldstone Effect
    -1,     //  575
    -1,     //  576
    -1,     //  577
    -1,     //  578
    -1,     //  579
    -1,     //  580
    -1,     //  581
    -1,     //  582
    -1,     //  583
    -1,     //  584
    -1,     //  585
    -1,     //  586
    -1,     //  587
    -1,     //  588
    -1,     //  589
    -1,     //  590
    -1,     //  591
    -1,     //  592
    -1,     //  593
    -1,     //  594
    -1,     //  595
    -1,     //  596
    -1,     //  597
    -1,     //  598
    -1,     //  599
    -1,     //  600
    -1,     //  601
    -1,     //  602
    -1,     //  603
    -1,     //  604
    -1,     //  605
    -1,     //  606
    -1,     //  607
    -1,     //  608
    -1,     //  609
    -1,     //  610
    -1,     //  611
    -1,     //  612
    -1,     //  613
    -1,     //  614
    -1,     //  615
    -1,     //  616
    -1,     //  617
    -1,     //  618
    -1,     //  619
    -1,     //  620
    -1,     //  621
    -1,     //  622
    -1,     //  623
    -1,     //  624
    -1,     //  625
    -1,     //  626
    -1,     //  627
    -1,     //  628
    -1,     //  629
    -1,     //  630
    -1,     //  631
    -1,     //  632
    -1,     //  633
    -1,     //  634
    -1,     //  635
    -1,     //  636
    -1,     //  637
    -1,     //  638
    -1,     //  639
    -1,     //  640
    -1,     //  641
    -1,     //  642
    -1,     //  643
    -1,     //  644
    -1,     //  645
    -1,     //  646
    -1,     //  647
    -1,     //  648
    -1,     //  649
    -1,     //  650
    -1,     //  651
    -1,     //  652
    -1,     //  653
    -1,     //  654
    -1,     //  655
    -1,     //  656
    -1,     //  657
    -1,     //  658
    -1,     //  659
    -1,     //  660
    -1,     //  661
    -1,     //  662
    -1,     //  663
    -1,     //  664
    -1,     //  665
    -1,     //  666
    -1,     //  667
    -1,     //  668
    -1,     //  669
    -1,     //  670
    -1,     //  671
    -1,     //  672
    -1,     //  673
    -1,     //  674
    -1,     //  675
    -1,     //  676
    -1,     //  677
    -1,     //  678
    -1,     //  679
    -1,     //  680
    -1,     //  681
    -1,     //  682
    -1,     //  683
    -1,     //  684
    -1,     //  685
    -1,     //  686
    -1,     //  687
    -1,     //  688
    -1,     //  689
    -1,     //  690
    -1,     //  691
    -1,     //  692
    -1,     //  693
    -1,     //  694
    -1,     //  695
    -1,     //  696
    -1,     //  697
    -1,     //  698
    -1,     //  699
    -1,     //  700
    -1,     //  701
    -1,     //  702
    -1,     //  703
    -1,     //  704
    -1,     //  705
    -1,     //  706
    -1,     //  707
    -1,     //  708
    -1,     //  709
    -1,     //  710
    -1,     //  711
    -1,     //  712
    -1,     //  713
    -1,     //  714
    -1,     //  715
    -1,     //  716
    -1,     //  717
    -1,     //  718
    -1,     //  719
    -1,     //  720
    -1,     //  721
    -1,     //  722
    -1,     //  723
    -1,     //  724
    -1,     //  725
    -1,     //  726
    -1,     //  727
    -1,     //  728
    -1,     //  729
    -1,     //  730
    -1,     //  731
    -1,     //  732
    -1,     //  733
    -1,     //  734
    -1,     //  735
    };
#pragma endregion

void __declspec(naked) LightingPatch_ASM()
{
    __asm
    {
        cmp [bFullLoS],0
        je lightold

        mov eax,0xff
        mov byte ptr [esp+4+0], al
        mov byte ptr [esp+4+1], al
        mov byte ptr [esp+4+2], al
        add dword ptr [esp], 0x72;
        ret
        lightold:
        push esi
        call D2COMMON_GetLevelIdFromRoom_I;
        ret
    }
}

void __declspec(naked) WeatherPatch_ASM()
{
    __asm
    {
        cmp [bNoWeather],0
        je rainold
        xor al,al
rainold:
        ret 0x04
    }
}

DWORD __declspec(naked) __fastcall D2CLIENT_clickParty_ASM(DWORD RosterUnit, DWORD Mode)
{
    __asm
    {
        mov eax, ecx
        jmp D2CLIENT_clickParty_I
    }
}

DWORD __declspec(naked) __fastcall D2DrawRectFrame_STUB(RECT* pRect)
{
    __asm
    {
        mov eax, ecx
        jmp D2CLIENT_DrawRectFrame
    }
}

VOID __declspec(naked) GameInput_Interception()
{
    __asm {
    pushad
        mov ecx, ebx
        call GameInput
        cmp eax, -1
    popad
    je BlockIt
    call D2CLIENT_InputCall_I
    ret

BlockIt:

    xor eax,eax
    ret
    }
}

void DumpTCs()
{
    Print("Dumping...");
    /*InitTCList();
    FILE* f;
    fopen_s(&f, "c:\\___\\tc_sup.txt", "w");
    for (int i = 0; i < 102; i++)
    {
        fprintf_s(f, "%d\n", GetSTC(i));
    }
    fclose(f);

    fopen_s(&f, "c:\\___\\tc_norm.txt", "w");
    for (int i = 0; i < 1000; i++)
    {
        fprintf_s(f, "%d\n", GetMTC(i));
    }
    fclose(f);*/

    FILE* f;
    fopen_s(&f, "c:\\___\\montxt_dump.txt", "w");
    for (int i = 0; i < 1000; i++)
    {
        fprintf_s(f, "%d:\n", i);
        MonsterTxt* m = D2CLIENT_GetMonsterTxt(i);
        if (!m)
            continue;

        fprintf_s(f, "%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", 
            m->tcs[0][0], m->tcs[0][1], m->tcs[0][2], m->tcs[0][3], 
            m->tcs[1][0], m->tcs[1][1], m->tcs[1][2], m->tcs[1][3], 
            m->tcs[2][0], m->tcs[2][1], m->tcs[2][2], m->tcs[2][3]);
    }
    fclose(f);

    Print("Dumped!");
}
DWORD __fastcall GameInput(wchar_t* wMsg)
{
    CHAR *argv[0x10];
    CHAR szBuffer[0x100] = "";
    WToC(wMsg, szBuffer);

    if (szBuffer[0] == cCommandPrefix[0])
    {
        INT argc = StringTokenize(szBuffer + 1, ' ', argv, 0x10);

        if (_strcmpi(argv[0], "reload") == 0)
        {
            readConfig ();
            ReadColorFile();
            DeleteBlobs();
            InitBlobs();
            PrintAtBottomLeft("ÿc4[xMap]ÿc0: Successfully reloaded configuration.");
        }

        if (_strcmpi(argv[0], "set") == 0 && argc == 3)
            setConfig(argv[1], argv[2]);
        if (_strcmpi(argv[0], "get") == 0 && argc == 2)
            getConfig(argv[1]);
        if (_strcmpi(argv[0], "ui") == 0 && argc == 2)
            D2CLIENT_SetUiVar(atoi(argv[1]), 0, 0);
        if (_strcmpi(argv[0], "wtf") == 0 && argc == 1)
            DumpTCs();
        if (_strcmpi(argv[0], "m") == 0)
        {
            UnitAny* pUnit = D2CLIENT_GetSelectedUnit();
            if (pUnit)
                Print("ID: %d", pUnit->dwUnitId);
            Print("Seaching...");
            for (Room1 *pRoom = D2CLIENT_GetPlayerUnit()->pAct->pRoom1; pRoom; pRoom = pRoom->pRoomNext)
            {
                for (UnitAny *pUnit = pRoom->pFirstUnit; pUnit; pUnit = pUnit->pListNext)
                {
                    //If it's an item, draw it on minimap
                    if (pUnit->dwType == UNIT_MISSILE)
                    {
                        Print("%d", pUnit->dwTxtFileNo);
                    }
                }
            }
        }
        if (_strcmpi(argv[0], "printentries") == 0)
            PrintConfigEntries();
        return -1;
    }
    return NULL;
}

BOOL Say(CHAR* lpMessage, ...)
{
    CHAR szBuffer[0x400] = "";
    va_list Args;

    if(!GameReady())
        return FALSE;

    va_start(Args, lpMessage);
    vsprintf(szBuffer, lpMessage, Args);
    va_end(Args);

    BYTE* aPacket = new BYTE[(INT)strlen(szBuffer) + 6];
    memset(aPacket, 0, (INT)strlen(szBuffer) + 6);

    aPacket[0] = 0x15;
    *(WORD*)&aPacket[1] = 1;
    memcpy(aPacket + 3, szBuffer, (INT)strlen(szBuffer));
    
    D2NET_SendPacket((INT)strlen(szBuffer) + 6, 1, aPacket);
    delete [] aPacket;

    return TRUE;
}

DWORD npcid = 0;

LONG WINAPI GameWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Toggles pToggles[] =
    {
        { nAutoPartyToggle, &bUseAutoParty, "Auto Party" },
        { nLifePercentToggle, &bShowPercents, "Life Percents" },
        { nShowStatsToggle, &bShowStats, "Stat Display" },
        { nScrollMapToggle, &bScrollMap, "Scroll Map" },
        { nActiveRoomsToggle, &bShowActiveRooms, "Active Rooms" },
        { nOutOfTownSelectKey, &bOutOfTownSelect, "Out Of Town Select" },
        { nSocketProtectKey, &bSocketProtect, "Socket Protection" },
        { nHideItemsKey, &cHideItems, "Hide Items" },
    };

    if (GameReady())
    {
        if (uMsg == WM_LBUTTONDOWN)
        {
            if (D2CLIENT_GetUiVar(0x01) && uViewingUnit != NULL && *p_D2CLIENT_MouseX >= 400)
                return NULL;

            /*UnitAny* pUnit= D2CLIENT_GetSelectedUnit();
            if (pUnit && pUnit->dwType == UNIT_OBJECT && pUnit->dwTxtFileNo == 0x3B)
            {
                Interact(pUnit->dwUnitId, UNIT_OBJECT, FALSE);
                return NULL;
            }*/

            if (wParam == 0x09 && *p_D2CLIENT_AutomapOn && !D2CLIENT_GetUiVar(UIVAR_NPCTRADE))
            {
                POINT pt;
                AutomapToScreen(&pt, *p_D2CLIENT_MouseX, *p_D2CLIENT_MouseY);
                CastXY(pt.x, pt.y, FALSE);
                /*Print("Me: %d %d", D2CLIENT_GetPlayerUnit()->pPath->xPos, D2CLIENT_GetPlayerUnit()->pPath->yPos);
                Print("Coords: %d %d", pt.x, pt.y);
                Print("Distance: %lf", CalculateDistance(D2CLIENT_GetPlayerUnit()->pPath->xPos, D2CLIENT_GetPlayerUnit()->pPath->yPos,
                                    pt.x, pt.y));
                Print("OK");*/
                return NULL;
            }
        }
        if (uMsg == WM_KEYUP && !D2CLIENT_GetUiVar(UIVAR_CHATINPUT))
        {
            for (int n = 0; n < ArraySize(pToggles); n++)
            {
                if (wParam == pToggles[n].nKey)
                {
                    *(PBOOL)pToggles[n].nVar = !*(PBOOL)pToggles[n].nVar;
                    char* nMode = (*(PBOOL)pToggles[n].nVar) ? "Enabled" : "Disabled";
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: %s %s.", nMode, pToggles[n].pMsg);
                }
            }
            if (wParam == nTPPKKey)
            {
                if (bEnableTPPK && OpenPortal())
                {
                    bHostilePlayers = TRUE;
                    bBackToTown = TRUE;
                }
            }
            if (wParam == nShowInvKey)
            {
                UnitAny* pUnit = D2CLIENT_GetSelectedUnit ();
                if (pUnit && pUnit->pInventory && pUnit->dwMode != 0 && pUnit->dwMode != 17 && pUnit->dwType == 0)
                {
                    uViewingUnit = pUnit;
                    if (!D2CLIENT_GetUiVar(0x01))
                        D2CLIENT_SetUiVar(0x01, 0, 0);
                }
            }

            //Reveal Map Key
            if (wParam == nRevealMapKey)
            {

                UnitAny *pUnit = D2CLIENT_GetPlayerUnit ();
                if (pUnit && !cMap->m_RevealedActs[pUnit->dwAct])
                {
                    SuspendThreadsInProcess(GetCurrentProcessId ());
                    ResumeThread(*((HANDLE*)0x6FC45348));
                    cMap->RevealAutomap();
                    ResumeThreadsInProcess(GetCurrentProcessId ());
                }
            }

            //open stash
            if (wParam == nOpenStashKey)
                OpenStash();
            if (wParam == nOpenCubeKey)
                OpenCube();
            if (wParam == nResynchKey)
            {
                Resynch();
                PrintAtBottomLeft("ÿc4[xMap]ÿc0: Resynchronized with server.");
            }

            if (wParam == nEnchantBotToggleKey)
            {
                if (!GetSkill(D2S_ENCHANT))
                    PrintAtBottomLeft("ÿc4[Ench Bot]ÿc0: Enchant skill not found!");
                else
                {
                    cEnchantBotToggle = !cEnchantBotToggle;

                    if(cEnchantBotToggle)
                    {
                        if (!bSilentBots)
                            Say("Hello everybody. Chant bot active. Commands are: %s, %s, %s", cEnchantMe.c_str(), cEnchantMerc.c_str(), cEnchantAll.c_str());
                    }
                    else
                        EnchantQueue.RemoveAll();
                
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: Enchant Bot %s", cEnchantBotToggle ? "Enabled" : "Disabled");
                }
            }

            if (wParam == nFollowBotToggleKey)
            {
                UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
                
                if (pPlayer && !STRING_EQUAL(pPlayer->pPlayerData->szName, cFollowBotLeaderName))
                {
                    bFollowBotToggle = !bFollowBotToggle;

                    bFollowBotWaiting = TRUE;

                    if (bFollowBotToggle)
                        PrintAtBottomLeft("ÿc4[xMap]ÿc0: Follow Bot Enabled. Waiting for %s to command.", cFollowBotLeaderName.size() > 0 ? cFollowBotLeaderName.c_str() : "<nobody>");
                    else
                        PrintAtBottomLeft("ÿc4[xMap]ÿc0: Follow Bot Disabled");
                }
                else
                    PrintAtBottomLeft("ÿc4[Follow Bot]ÿc0: Can't follow yourself, %s", pPlayer->pPlayerData->szName);

            }
        }
        if (uMsg == WM_KEYDOWN && !D2CLIENT_GetUiVar(UIVAR_CHATINPUT))
        {
            if (wParam == VK_LEFT)
                ScrollMap(-2, 0);
            if (wParam == VK_RIGHT)
                ScrollMap(+2, 0);
            if (wParam == VK_UP)
                ScrollMap(0, -2);
            if (wParam == VK_DOWN)
                ScrollMap(0, +2);

            if (wParam == nFastToTownKey && !TestPlayerInTown(D2CLIENT_GetPlayerUnit()))
            {
                if (OpenPortal())
                    bBackToTown = TRUE;
            }

            if (wParam == nOpenPortalKey)
                OpenPortal();

            //fast exit key
            if (wParam == nFastExitKey)
                ExitGame_ASM();    

            //Leader keys
            //if (wParam == 0x41 + 'j'-'a')
            if (wParam == nBindNPCKey)
            {
                UnitAny* targetnpc = D2CLIENT_GetCurrentInteractingNPC();
                if (!targetnpc)
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: You must first interact with an npc.");
                else
                {
                    if (!npcid)
                    {
                        npcid = targetnpc->dwUnitId;
                        PrintAtBottomLeft("ÿc4[xMap]ÿc0: NPC bound with id %d", npcid);
                    }
                    else
                    {
                        npcid = targetnpc->dwUnitId;
                        PrintAtBottomLeft("ÿc4[xMap]ÿc0: NPC rebound with id %d", npcid);
                    }
                }
            }

            //if (wParam == 0x41 + 'k'-'a')
            if (wParam == nPullNPCKey)
            {
                if (npcid)
                {
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: Pulling NPC with id %d!", npcid);
                    MoveNPC(npcid);
                }
                else
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: You must bind an NPC first!");
            }

            //if (wParam == 0x41 + 'l'-'a')
            if (wParam == nInteractNPCKey)
            {
                if (npcid)
                {
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: Interacting with an NPC with id %d", npcid);
                    Interact(npcid, UNIT_NPC, FALSE);
                }
                else
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: Use must bind and NPC first!");

            }

        }
    }

    return (LONG)CallWindowProcA(OldWNDPROC, hWnd, uMsg, wParam, lParam);
}

void __fastcall NextGameNamePatch(Control* box, BOOL (__stdcall *FunCallBack)(Control*,DWORD,DWORD))
{
    if (!bAutoLastGameName)
        return;

    if (strlen(szLastGameName) == 0)
        return;

    wchar_t *wszLastGameName = new wchar_t[8192];
    memset(wszLastGameName, 0, 8192);
    CToW(szLastGameName, wszLastGameName);

    D2WIN_SetControlText(box, wszLastGameName);
    D2WIN_SelectEditBoxText(box, box->wText);
    // original code
    D2WIN_SetEditBoxProc(box, FunCallBack);
    delete wszLastGameName;
}

void __declspec(naked) ItemNamePatch_ASM()
{
    __asm
    {
//ebx = ptr unit item
//edi = ptr item name string
        mov ecx, edi
        mov edx, ebx
        call ItemNamePatch
        mov al, [ebp+0x12a]
        ret
    }
}

void __fastcall ItemNamePatch(wchar_t *name, UnitAny *item)
{
    char nName[1024];
    WToC(name, nName);

    int itemno=item->dwTxtFileNo;
    ItemTxt* itemtxt = D2COMMON_GetItemTxt(itemno);

    //int id = njipClassId[GetItemCode(itemtxt).ToLowerCase()];
    int id = item->dwTxtFileNo + 1;
    if (IsItemRune(id) && bShowRuneNumbers)
    {
        char c[1024];
        sprintf_s(c, sizeof(c), "%s(%d)", nName, GetRuneNumber(id));
        strcpy_s(nName, sizeof(nName), c);
    }

    DWORD isEthereal = item->pItemData->dwFlags & 0x00400000;
    if (isEthereal && bShowItemEthereal)
    {
        char szEth[6] = "{E}";
        strcat_s(nName, sizeof(nName), szEth);
    }
    int numSockets = D2COMMON_GetUnitStat(item, 194, 0);
    if (numSockets > 0 && bShowItemSockets)
    {
        char szSocket[5];
        sprintf_s(szSocket, sizeof(szSocket), "(%i)", numSockets);
        strcat_s(nName, sizeof(nName), szSocket);
    }

    if (bShowItemiLvl && !NoiLvl(itemtxt->dwCode))
    {        
        char szLvl[10];
        sprintf_s(szLvl, 10, "(L%i)", item->pItemData->dwItemLevel);
        strcat_s(nName, sizeof(nName), szLvl);
    }

    if (bShowItemValues)
    {
        char szItemValue[20];
        int nItemValueNpc = 0x201;
        sprintf_s(szItemValue, 20, "($%i)", D2COMMON_GetItemValue(D2CLIENT_GetPlayerUnit(), item, D2CLIENT_GetDifficulty(), D2CLIENT_GetQuestInfo(), nItemValueNpc, 1));
        strcat_s(nName, sizeof(nName), szItemValue);
    }

    /*if (GetItemCode(itemtxt).Trim() == "gld")
    {
        Print("1");
        if (D2COMMON_GetUnitStat(item, STAT_GOLD, 0) >= nGoodGoldCount)
        {
            Print("2");
            char c[1024];
            sprintf_s(c, sizeof(c), "ÿc%c%s", "3", nName);
            strcpy_s(nName, sizeof(nName), c);
        }
    }
    else*/
    if (bChangeItemColors && !itemCol.IsEmpty())
    {

        ItemDesc tempDesc;
        tempDesc.itemCode.push_back(id);
        tempDesc.itemQuality = GetItemQualityFromD2(item->pItemData->dwQuality);
        tempDesc.numSockets = GetItemNumSocketsFromD2(numSockets);
        tempDesc.isEthereal = isEthereal;
        tempDesc.flags = GetMyItemFlags(id);

        /*itemColCS.Lock();
        for (ItemDescList::iterator i = itemCol.begin(); i != itemCol.end(); i++)
        {
            if ((*i)->itemColor != '\0')
                if (CompareItemWithDescription(&tempDesc, *i))
                {
                    char c[1024];
                    sprintf_s(c, sizeof(c), "ÿc%c%s", (*i)->itemColor, nName);
                    strcpy_s(nName, sizeof(nName), c);
                    break;
                }
        }
        itemColCS.Unlock();*/

        for (int i = 0; i < itemCol.GetSize(); i++)
        {
            if (itemCol[i]->itemColor != '\0')
                if (CompareItemWithDescription(&tempDesc, itemCol[i]))
                {
                    char c[1024];
                    sprintf_s(c, sizeof(c), "ÿc%c%s", itemCol[i]->itemColor, nName);
                    strcpy_s(nName, sizeof(nName), c);
                    break;
                }
        }

        //Print("%d", item->dwTxtFileNo);

    }

    CToW(nName, name);
}

DWORD __declspec(naked) __fastcall TestPvpFlag_STUB(DWORD planum1, DWORD planum2, DWORD flagmask)
{
    __asm
    {
        push esi
        push [esp+8] // flagmask
        mov esi, edx
        mov edx, ecx
        call D2CLIENT_TestPvpFlag_I
        pop esi
        ret 4
    }
}

DWORD __declspec(naked) __fastcall D2CLIENT_GetUIVar_STUB(DWORD varno)
{
    __asm 
    {
        mov eax, ecx;
        jmp D2CLIENT_GetUiVar_I;
    }
}
/*DWORD __declspec(naked) __fastcall D2CLIENT_GetUnitFromId_STUB(DWORD unitid, DWORD unittype)
{
    __asm
    {
        pop eax;
        push edx; // unittype
        push eax; // return address

        shl edx, 9;
        mov eax, p_D2CLIENT_pUnitTable;
        add edx, eax;
        mov eax, ecx; // unitid
        and eax, 0x7F;
        jmp D2CLIENT_GetUnitFromId_I;
    }
}*/

DWORD __declspec(naked) __fastcall D2CLIENT_GetInventoryId_STUB(UnitAny* pla, DWORD unitno, DWORD arg3)
{
    __asm
    {
        push    esi
        push    edi
        test    ecx, ecx
        jz      short loc_6FAB1952
        mov     eax, p_D2CLIENT_UnitListHdr
        mov        eax, [eax]
        mov     ecx, [ecx]UnitAny.dwUnitId
        test    eax, eax
        jz      short loc_6FAB1952
        mov     esi, [esp+0x0c]

    loc_6FAB1936:
        cmp     [eax+4], edx
        jnz     short loc_6FAB194B
        cmp     [eax+0Ch], ecx
        jnz     short loc_6FAB194B
        test    esi, esi

        jnz     short loc_6FAB195A
        mov     edi, [eax+20h]
        test    edi, edi
        jz      short loc_6FAB195A

    loc_6FAB194B:
        mov     eax, [eax+30h]
        test    eax, eax
        jnz     short loc_6FAB1936

    loc_6FAB1952:
        pop     edi
        or      eax, 0FFFFFFFFh
        pop     esi
        retn    4
    loc_6FAB195A:
        mov     eax, [eax+8]
        pop     edi
        pop     esi
        retn    4
    }
}
void __declspec(naked) ViewInventoryPatch1_ASM()
{
    __asm
    {
        push eax;
        call ViewInventoryPatch1;
        mov esi, eax;
        pop eax;
        ret;
    }
}
void __declspec(naked) ViewInventoryPatch2_ASM()
{
    __asm
    {
        push eax;
        call GetViewUnit;
        mov ebx, eax;
        pop eax;
        ret;
    }
}
void __declspec(naked) ViewInventoryPatch3_ASM()
{
    __asm
    {
        push eax;
        push ebx;
        call GetViewUnit;

        mov ebx, [edi];
        cmp ebx, 1;
        je OldCode;

        mov edi, eax;

        OldCode:
        pop ebx;
        pop eax;
        test eax, eax;
        mov ecx, dword ptr [edi + 0x60];

        ret;
    }
}
UnitAny* GetViewUnit()
{
    if (!uViewingUnit)
        return D2CLIENT_GetPlayerUnit();

    return uViewingUnit;
}

UnitAny *ViewInventoryPatch1 ()
{
    UnitAny *pUnit = GetViewUnit ();
    UnitAny *pMe = D2CLIENT_GetPlayerUnit ();

    if(pUnit->dwUnitId == pMe->dwUnitId)
        return pMe;

    TextHook(560, 300, 0, false, 0, 1, "%s", pUnit->pPlayerData->szName);
    //ShowStats(pUnit);
    return GetViewUnit ();
}
void __stdcall ShakeScreenPatch(DWORD *xpos, DWORD *ypos)
{
    D2CLIENT_CalcShake(xpos, ypos);
    if (bScrollMap)
    {
        *p_D2CLIENT_xMapShake += xMapShake;
        *p_D2CLIENT_yMapShake += yMapShake;
    }

    *xpos += *p_D2CLIENT_xMapShake;
    *ypos += *p_D2CLIENT_yMapShake;
}

void ScrollMap(char xinc, char yinc)
{
    if (bScrollMap)
    {
        xMapShake += xinc*8;
        yMapShake += yinc*8;
    }
    else if (*p_D2CLIENT_AutomapOn)
    {
        p_D2CLIENT_ptAutomap->x += xinc*8;
        p_D2CLIENT_ptAutomap->y += yinc*8;
    }
}

void __declspec(naked) PermShowOrbPatch_ASM()
{
    __asm
    {
        cmp [bTogglePermShowOrbsText], 0
        jz nextcode
        add dword ptr [esp], 0x25
        ret
    nextcode:
        call D2GetScreenSizeY
        cmp ebx, 0x1E
        ret
    }
}

void __declspec(naked) PermShowOrbPatch2_ASM()
{
    __asm
    {
        and word ptr [esp+0x18], 0
        ret
    }
}

void __declspec(naked) PermShowOrbPatch3_ASM()
{
    __asm
    {
        cmp [bTogglePermShowOrbsText], 0
        jz nextcode
        add dword ptr [esp], 0x2D
        ret
    nextcode:
        call D2GetScreenSizeX
        mov ecx, eax
        call D2GetScreenSizeY
        ret
    }
}

void __declspec(naked) MonsterDeathPatch_ASM()
{
    __asm
    {
        cmp [cMonsterDeathAnims+eax],0
        je noanim
        cmp eax,0x100 //original code
        ret
    noanim:
        pop eax // discard return address
        pop esi // restore esi, check prolog of this function carefully
        ret 4 // return to upper level function
    }
}

BOOL __fastcall InfravisionPatch(UnitAny *unit)
{
    /*if (tToggleChickenDangerousMonster.flag && unit->nUnitType == UNITNO_MONSTER && unit->eMode && unit->eMode != 0x0C) {
        if (!TestPlayerInTown(D2CLIENT_GetPlayerUnit())) {
            CheckPlayerStat(unit);
        } else if (fDangerousMonsterActive) {
            fDangerousMonsterActive = 0;
        }
    }*/
    //if (InfravisionPatch2(unit)) 
    //    return FALSE; //true == hide
    //return TRUE/*!tToggleInfravision.flag*/ ? InfravisionPatch3(unit) : FALSE;//false=infravision
    return InfravisionPatch3(unit);
    //return TRUE;
}

void __declspec(naked) InfravisionPatch_ASM()
{
    __asm
    {
        mov ecx, esi
        call InfravisionPatch
        add dword ptr [esp], 0x72
        ret
    }
}

BOOL PlainScreen()
{
    return (!D2CLIENT_GetUiVar(UIVAR_INVENTORY) && !D2CLIENT_GetUiVar(UIVAR_STATS) &&
        !D2CLIENT_GetUiVar(UIVAR_SKILLS) && !D2CLIENT_GetUiVar(UIVAR_PARTY) && 
        !D2CLIENT_GetUiVar(UIVAR_STASH) && !D2CLIENT_GetUiVar(UIVAR_CUBE) &&
        !D2CLIENT_GetUiVar(UIVAR_PET));
}

BOOL __fastcall InfravisionPatch3(UnitAny *unit)
{
    if (!unit)
        return TRUE;
    switch(unit->dwType)
    {
        case UNIT_PLAYER:
            if (!unit->dwMode || unit->dwMode == 0x11 || bInfravision)
                return FALSE;
            break;
        case UNIT_MONSTER:
            if (bDisableMonsterDeathAnims && unit->dwMode == NPC_MODE_DEATH)
                return TRUE;
            if (bHideCorpses && unit->dwMode == NPC_MODE_DEAD)
                return TRUE;
            if (!unit->dwMode || unit->dwMode == 0x0C || bInfravision) //do not hide corpses and dying monsters behind walls
                return FALSE;
            break;
        case UNIT_ITEM:
            if (cHideItems && !itemCol.IsEmpty())
            {
                ItemTxt* itemtxt = D2COMMON_GetItemTxt(unit->dwTxtFileNo);

                //int id = njipClassId[GetItemCode(itemtxt).ToLowerCase()];
                int id = unit->dwTxtFileNo + 1;
                int numSockets = D2COMMON_GetUnitStat(unit, 194, 0);
                DWORD isEthereal = unit->pItemData->dwFlags & 0x00400000;

                ItemDesc tempDesc;
                tempDesc.itemCode.push_back(id);
                tempDesc.itemQuality = GetItemQualityFromD2(unit->pItemData->dwQuality);
                tempDesc.numSockets = GetItemNumSocketsFromD2(numSockets);
                tempDesc.isEthereal = isEthereal;
                tempDesc.flags = GetMyItemFlags(id);

                /*for (ItemDescList::iterator i = itemCol.begin(); i != itemCol.end(); i++)
                    if ((*i)->hide)
                        if (CompareItemWithDescription(&tempDesc, *i))
                            return TRUE;*/
                for (int i = 0; i < itemCol.GetSize(); i++)
                    if (CompareItemWithDescription(&tempDesc, itemCol[i]))
                        if (itemCol[i]->hide)
                            return TRUE;
                        else
                            break;
            }
            break;
        default:
            return FALSE;
    }

    Level *curlvl = GetUnitLevel(unit);
    if (curlvl && !D2COMMON_GetFunUnk_5(curlvl->dwLevelNo))
        return FALSE;

    return D2COMMON_TestFunUnk_6(D2CLIENT_GetPlayerUnit(), unit, 2);
}

//BOOL __fastcall InfravisionPatch2(UnitAny *unit)
//{
    //to do in future
    /*BYTE c;
    switch(unit->nUnitType) {
    case UNIT_MONSTER:
        if (!tToggleHiddenCorpse.flag && unit->eMode == 0x0C) {
            return afMonsterCorpses[unit->nTxtFileNo] == 0;
        }
        break;
    case UNIT_MISSILE:
        if (!tToggleHiddenCorpse.flag && (unit->fFlags0)) {
            return afMissileCorpses[unit->nTxtFileNo] == 0;
        }
        break;
    case UNIT_ITEM:
        c = (BYTE)GetItemColour(unit)[1];
        if (c == 0xFC) return TRUE;
        if (!tToggleHiddenItems.flag) {
            if (c == 0xFD)
                return unit->pItemData->dwItemLevel == nHiddenItemLevel;
            else
                return c == 0xFE;
        }
        break;
    }*/
//    return FALSE;
//}

void D2LogMessage(wchar_t** buf)
{
    if (GameReady())
        D2CLIENT_PrintGameString(*buf, 0);
    /*try
    {
        char path[1024];
        sprintf_s(path, sizeof(path), "%s\\D2Messages.log", szPath);

        FILE* hfile;
        fopen_s(&hfile, path, "a");
        fprintf_s(hfile, buf);
        fprintf_s(hfile, "\n");
        fclose(hfile);
    }
    catch (exception &e)
    {
        //
    }*/
}

void __declspec(naked) DrawPlayerBlobPatch_ASM()
{
    __asm
    {
        push UNIT_PLAYER
        jmp DrawAutomapBlob_ASM
    }
}

void __declspec(naked) DrawAutomapBlob_ASM()
{
    __asm
    {
        push [esp+8]
        mov edx, eax
        call DrawAutomapBlob
        ret 4
    }
}

void __fastcall DrawAutomapBlob(int xpos, int ypos, DWORD col, DWORD unittype)
{
    if (D2CLIENT_GetAutomapSize())
    {
        xpos -= 1;
        ypos += 5;
    }

    if (!cUnitBlobCells[unittype])
    {
        static char blines[][2] = { 0,-2, 4,-4, 8,-2, 4,0, 8,2, 4,4, 0,2, -4,4, -8,2, -4,0, -8,-2, -4,-4, 0,-2 };
        for (int i = 0; i < ArraySize(blines)-1; i++)
            D2GFX_DrawLine(xpos+blines[i][0], ypos+blines[i][1], xpos+blines[i+1][0], ypos+blines[i+1][1], col, 0xff);
    }
    else
    {
        myDrawAutomapCell(cUnitBlobCells[unittype], xpos, ypos, (BYTE)col, FALSE);
    }
}

void __declspec(naked) DrawPlayerBlobPatch2_ASM()
{
    __asm
    {
//dl = col
//ecx = x pos
//eax = y pos
        push UNIT_PLAYER
        push edx
        mov edx,eax
        call DrawAutomapBlob
//        add dword ptr [esp], 0x36
        ret
    }
}

void __declspec(naked) DrawObjectBlobPatch_ASM()
{
    __asm
    {
        push UNIT_OBJECT
        jmp DrawAutomapBlob_ASM
    }
}

void __declspec(naked) DrawMonsterBlobPatch_ASM()
{
    __asm
    {
        push UNIT_MONSTER
        jmp DrawAutomapBlob_ASM
    }
}

void __declspec(naked) MonsterBlobColPatch_ASM()
{
    __asm
    {
//esi = ptr unit monster
//ebx = ptr colour
//return eax = draw flag
        mov ecx,esi
        call MonsterBlobColPatch
        mov [ebx],al
        sub al,-4
        setb al
        movzx eax,al
        pop esi
        add esp, 0x0C
        ret
    }
}

BYTE __fastcall MonsterBlobColPatch(UnitAny *mon)
{
    if (mon->dwType == UNIT_MONSTER)
    {
        if (mon->dwMode && mon->dwMode != 0x0C)
            return MonsterBlobColPatch2(mon);

        /*if (tToggleAutomapCorpse.flag) {
            int index = D2COMMON_GetMonsterColorIndex(mon, 0);
            if (index) {
                if (anMonsterCorpseColors[index] == (BYTE)-1) {
                    if (mon->pMonsterData->fChamp & 1) 
                        return nChampionMonsterColor;
                    if (mon->pMonsterData->fMinion & 1) 
                        return nMinionMonsterColor;
                    if (mon->pMonsterData->fBoss & 1) 
                        return nBossMonsterColor;
                    return nNormalMonsterColor;
                }
                return 0xff;
            }
        }*/
    }
    return MixedBlobColPatch(mon);
}

BYTE __fastcall MonsterBlobColPatch2(UnitAny *pUnit)
{
    if (bShowMonsters)
    {
        UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
        INT nColor = -1;

        if (pUnit->dwMode == NPC_MODE_DEATH || pUnit->dwMode == NPC_MODE_DEAD)
            return -2;

        if (nMonsterColors[pUnit->dwTxtFileNo] > 0)
            nColor = nMonsterColors[pUnit->dwTxtFileNo];

        if (nMonsterColors[pUnit->dwTxtFileNo] == -1 && nColor == -1)
        {
            if (pUnit->pMonsterData->fBoss & 1)
                nColor = nBossMonsterColor;
            else if (pUnit->pMonsterData->fChamp & 1)
                nColor = nChampionMonsterColor;
            else if (pUnit->pMonsterData->fMinion & 1)
                nColor = nMinionMonsterColor;
            else
                nColor = nNormalMonsterColor;
        }

        DWORD dwOwner = pUnit->dwOwnerId;// D2CLIENT_GetMonsterOwner(pUnit->dwUnitId);
        if(nColor == -1)
        {
            if (dwOwner == pPlayer->dwUnitId)
            {
                if (!IsMercClassId(pUnit->dwTxtFileNo))
                    nColor = 0x95;
            }
            else
            {
                RosterUnit* pOwner = FindPartyById(dwOwner);
                if (pOwner)
                {
                    DWORD dwFlags = GetPvpFlags(pOwner->dwUnitId);
                    if(dwFlags & PVP_HOSTILED_BY_YOU || dwFlags & PVP_HOSTILED_YOU)
                    nColor = 0x66;
                    if (pOwner->dwUnitId == pPlayer->dwUnitId)
                    nColor = 0x95;
                }
            }
        }
        
        if (nColor > 0)
        {
#pragma region MonsterTxts
            char nMonTxt[128] = "";

            //get auras and enchantments
            if (bShowEnchantments && (pUnit->pMonsterData->fBoss & 1 || pUnit->pMonsterData->fChamp & 1)) 
            {
                int aura = 0, enchno;
                for (int i = 0; i < ArraySize(pUnit->pMonsterData->anEnchants); ++i) 
                {
                    enchno = pUnit->pMonsterData->anEnchants[i];
                    if (enchno == 0)
                        break;
                    if (enchno == 30)
                        aura = 1;
                    if (enchno < 32)
                        strcat_s(nMonTxt, cEnchDescSymbols[enchno].c_str());
                }
    
                if (aura) 
                {
                    //NOTE :- testing if monster effected by aura, NOT source of aura
                    static BYTE states[7] = { 0x21, 0x23, 0x28, 0x2b, 0x2e, 0x1c, 0x31 };
                    for (int i = 0; i < ArraySize(states); i++)
                    {
                        if (D2COMMON_GetUnitState(pUnit, states[i]))
                            strcat_s(nMonTxt, cAuraDescSymbols[i].c_str());
                    }
                }
            }

            if ((int)D2COMMON_GetUnitStat(pUnit, STAT_DAMAGE_REDUCED, 0) >= 100)//Physical
            {
                strcat_s(nMonTxt, "ÿc4");
                strcat_s(nMonTxt, cMonsterImmunitySymbol.c_str());
            }
            if ((int)D2COMMON_GetUnitStat(pUnit, STAT_COLD_RESIST, 0) >= 100)//Cold
            {
                strcat_s(nMonTxt, "ÿc3");
                strcat_s(nMonTxt, cMonsterImmunitySymbol.c_str());
            }
            if ((int)D2COMMON_GetUnitStat(pUnit, STAT_FIRE_RESIST, 0) >= 100)//Fire
            {
                strcat_s(nMonTxt, "ÿc1");
                strcat_s(nMonTxt, cMonsterImmunitySymbol.c_str());
            }
            if ((int)D2COMMON_GetUnitStat(pUnit, STAT_LIGHTING_RESIST, 0) >= 100)//Light
            {
                strcat_s(nMonTxt, "ÿc9");
                strcat_s(nMonTxt, cMonsterImmunitySymbol.c_str());
            }
            if ((int)D2COMMON_GetUnitStat(pUnit, STAT_POSION_RESIST, 0) >= 100)//Poison
            {
                strcat_s(nMonTxt, "ÿc2");
                strcat_s(nMonTxt, cMonsterImmunitySymbol.c_str());
            }
            if ((int)D2COMMON_GetUnitStat(pUnit, STAT_MAGIC_RESIST, 0) >= 100)//Magic
            {
                strcat_s(nMonTxt, "ÿc8");
                strcat_s(nMonTxt, cMonsterImmunitySymbol.c_str());
            }                                

            if (strlen(nMonTxt) > 0)
                TextHook(pUnit->pPath->xPos - 2, pUnit->pPath->yPos, 0, true, 4, 1, "%s", nMonTxt);
#pragma endregion
            return nColor;
        }
    }
    return -2;
}

BYTE __fastcall MixedBlobColPatch(UnitAny *pUnit)
//note will use bad text colour for stash if dont return -1
{
    if (pUnit->dwType == UNIT_OBJECT) 
    {
        UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
        if (bShowAutomapChests && IsObjectChest(pUnit->dwTxtFileNo) && !pUnit->dwMode) 
            return (pUnit->pObjectData->fChestLocked) ? nLockedChestColor : nOpenChestColor;

        if(pUnit->pObjectData->nShrineNo && pUnit->pObjectData->pTxt->nAutoMap == 310 && pUnit->pObjectData->pTxt->nSubClass & 1 &&
            pUnit->pObjectData->nShrineNo <= 22)
        {
            bool found=false;
            for (int i = 0; i < cMap->m_Shrines.GetSize(); i++)
            {
                if (cMap->m_Shrines[i]->nAct == pPlayer->dwAct && 
                    CalculateDistance(cMap->m_Shrines[i]->nX, cMap->m_Shrines[i]->nY, 
                        pUnit->pObjectPath->dwPosX, pUnit->pObjectPath->dwPosY) < 5)
                {
                    cMap->m_Shrines[i]->ID = pUnit->pObjectData->nShrineNo;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                ShrineDesc* sd = new ShrineDesc;
                sd->ID = pUnit->pObjectData->nShrineNo;
                sd->nX = pUnit->pObjectPath->dwPosX;
                sd->nY = pUnit->pObjectPath->dwPosY;
                sd->nAct = pPlayer->dwAct;
                cMap->m_Shrines.Add(sd);
            }
        }
    }
    else if (pUnit->dwType == UNIT_MISSILE)
    {
        if (bShowMissiles)
        {
            INT nColor = 0;
            DWORD dwFlags = 0;
            UnitAny* pTempUnit;
            UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();

            if (!pUnit->dwOwnerId)
                return -1;

            //crap missiles from crackin frozen mob
            if (pUnit->dwTxtFileNo == 344 || pUnit->dwTxtFileNo == 345 || //ice melt
                pUnit->dwTxtFileNo >= 115 && pUnit->dwTxtFileNo <= 117 ||
                pUnit->dwTxtFileNo >= 18 && pUnit->dwTxtFileNo <= 21 || //bloosd
                pUnit->dwTxtFileNo >= 272 && pUnit->dwTxtFileNo <= 275 || //chill break
                pUnit->dwTxtFileNo == 95 || //chillblood?
                pUnit->dwTxtFileNo >= 635 && pUnit->dwTxtFileNo <= 639 // baal room breaking
                )
                return -1;

            if (pUnit->dwOwnerId == pPlayer->dwUnitId)
                nColor = nYourMissileColor;
    
            if (!nColor && pUnit->dwOwnerType == UNIT_PLAYER)
            {
                dwFlags = GetPvpFlags(pUnit->dwOwnerId);
                if (dwFlags & PVP_HOSTILED_BY_YOU || dwFlags & PVP_HOSTILED_YOU)
                    nColor = nHostileMissileColor;
                if (dwFlags & PVP_ALLIED_WITH_YOU)
                    nColor = nPartyMissileColor;

                if (!nColor)
                    nColor = nNeutralMissileColor;
            }

            if (!nColor && pUnit->dwOwnerType == UNIT_MONSTER)
            {
                pTempUnit = D2CLIENT_FindUnit(pUnit->dwOwnerId, UNIT_MONSTER);
                if (!pTempUnit)
                    return -1;

                //here we check if it's a players' monster missile
                RosterUnit* pTempRoster = FindPartyById(D2CLIENT_GetMonsterOwner(pTempUnit->dwUnitId));
                if (pTempRoster)
                {
                    if (pTempRoster->dwUnitId == pPlayer->dwUnitId)
                        nColor = nYourMissileColor;
                    else
                    {
                        dwFlags = GetPvpFlags(pTempRoster->dwUnitId);
                        if (dwFlags & PVP_HOSTILED_YOU || dwFlags & PVP_HOSTILED_BY_YOU)
                            nColor = nHostileMissileColor;
                    }
                }
                else
                    nColor = nHostileMissileColor;

            }
            if (nColor > 0)
                return nColor;
        }
    }
    else if (pUnit->dwType == UNIT_ITEM)
    {
        if (bDrawAutomapItems && !itemCol.IsEmpty())
        {
            int itemno = pUnit->dwTxtFileNo;
            ItemTxt* itemtxt = D2COMMON_GetItemTxt(itemno);
            //string itemCode = itemtxt->szCode;
            int numSockets = D2COMMON_GetUnitStat(pUnit, 194, 0);
            DWORD isEthereal = pUnit->pItemData->dwFlags & 0x00400000;
                        
            ItemDesc tempDesc;
            //int id = njipClassId[GetItemCode(itemtxt).ToLowerCase()];
            int id = pUnit->dwTxtFileNo + 1;
            tempDesc.itemCode.push_back(id);
            tempDesc.itemQuality = GetItemQualityFromD2(pUnit->pItemData->dwQuality);
            tempDesc.numSockets = GetItemNumSocketsFromD2(numSockets);
            tempDesc.isEthereal = isEthereal;
            tempDesc.flags = GetMyItemFlags(id);

            int color = -1;

            for (int i = 0; i < itemCol.GetSize(); i++)
            {
                if (itemCol[i]->hide && cHideItems)
                    break;
                if (itemCol[i]->showOnMap && itemCol[i]->onMapColor != -1)
                    if (CompareItemWithDescription(&tempDesc, itemCol[i]))
                    {
                        color = itemCol[i]->onMapColor;
                        break;
                    }

            }

            if (color != -1)
                return color;

        }
    }
    return -1;
}

void __declspec(naked) DrawItemBlobPatch_ASM()
{
    __asm
    {
//eax = unit type-2
//edi = x pos
//ebx = y pos
//[esp+0x10] = col
        test eax,eax
        jne notunit2
//original code
        ret
notunit2:
        add eax,2
        push eax
        push dword ptr [esp+0x18]
        mov ecx,edi
        mov edx,ebx
        call DrawAutomapBlob
        add dword ptr [esp], 0x59
        ret
    }
}

map<long, long> m;

void __stdcall DrawAutomapCellPatch(CellContext *pCellContext, DWORD xpos, DWORD ypos, RECT *cliprect, DWORD bright)
{
    long cellno = pCellContext->nCellNo;
        //if (-cellno == (int)D2CLIENT_GetPlayerUnit()->pAct->pMisc->dwStaffTombLevel )

    /*int* cellno = (int*)&(pCellContext->nCellNo);
    if (*cellno < 0)
        Print("%d", *cellno);*/

    /*if (cellno < 0) {
        //Print("True");
        if (1) {
            char nLevelName[70];
            strcpy_s(nLevelName, sizeof(nLevelName), D2COMMON_GetLevelTxt(-cellno)->szName);
            if (-cellno == (int)D2CLIENT_GetPlayerUnit()->pAct->pMisc->dwStaffTombLevel)
                strcat_s(nLevelName, sizeof(nLevelName), "ÿc2*");
            //Print("%d %d", xpos, ypos);
            TextHook(xpos, ypos, 0, true, 4, 1, "%s", nLevelName);
        }
        return;
    }*/
    if (cellno == CELLNO_WAYPOINT && cWaypointCell != 0)
    {
        
        pCellContext->nCellNo = 0;
        pCellContext->pCellFile = cWaypointCell;
        xpos += (D2CLIENT_GetAutomapSize() ? 4 : 8)-(cWaypointCell->cells[0]->width/2);
        ypos += (D2CLIENT_GetAutomapSize() ? 4 : 0);
    }
    if (cellno == CELLNO_SHRINE)
    {
        pCellContext->nCellNo = 0;
        //pCellContext->pCellFile = NULL;
    }
    /*if (((cellno - CELLNO_MYSHRINES) >= 0) && (cellno - CELLNO_MYSHRINES < NUMOF_SHRINES)) {
        CellFile* myshrine = cShrineBlobCells[cellno - CELLNO_MYSHRINES];
        if (myshrine) {
            pCellContext->pCellFile = myshrine;
            pCellContext->nCellNo = 0;
            xpos += (D2CLIENT_GetAutomapSize() ? 4 : 8)-(myshrine->cells[0]->width/2);
        } else {
            pCellContext->nCellNo = CELLNO_SHRINE;
        }
    }*/
    D2GFX_DrawAutomapCell(pCellContext, xpos, ypos, cliprect, bright);
}

BYTE fPlayerInTown;
void __declspec(naked) OutTownSelectPatch1_ASM(/* four args on the stack*/)
{
    __asm
    {
        push [esp+0x14] // parameter 4
        push [esp+0x14] // parameter 3
        push [esp+0x14] // parameter 2
        push [esp+0x14] // parameter 1
        push outcode
//original code
        sub esp, 0x20
        push ebp
        xor ebp, ebp
        /* esp adjustment sum up
         *    push ebp        == 4
         *    sub esp, 0x20    == 0x20
         *    5 push insts    == 0x14
         */
        jmp dword ptr [esp+4+0x20+0x14] //TODO:check this function carefully
    outcode:
        mov fPlayerInTown, 0
        add esp, 4
        ret 0x10
    }
}

int __fastcall OutTownSelectPatch2(UnitAny *unit)
{
    if (!fPlayerInTown && ViewTestUnit(unit))
    {
        //uviewing
        if (bOutOfTownSelect || TestPlayerInTown(unit))
            return 1;
    }
    return -1;
}

void __declspec(naked) OutTownSelectPatch2_ASM()
{
    __asm
    {
        shr eax, 0x15
        and eax, 1
        jnz donothing
        mov ecx, ebp
        call OutTownSelectPatch2;
        cmp al, 0xFF
        jz quitcode
        add dword ptr [esp], 0xA2 // adjust return address
        mov [esp+4+0x34], eax // save return result
        pop eax // return address to eax
        push esi // push esi and edi because the return address skips these two instructions
        push edi
        jmp eax
    donothing:
        ret
    quitcode:
        xor eax, eax
        ret
    }
}

void __declspec(naked) OutTownSelectPatch3_ASM()
{
    __asm
    {
        cmp fPlayerInTown, 0
        jz outcode
        mov ecx, ebp
        call InfravisionPatch3
        cmp al, 1
        ret
    outcode:
        shr eax, 7
        and eax, 1
        ret
    }
}

BOOL ViewTestUnit(UnitAny *unit)
{
    if (unit && unit->dwType == UNIT_PLAYER)
    {
        if (unit->pInventory)
        {
            if (unit->dwMode)
                return unit->dwMode != 0x11;
        }
        else if (unit->dwType == UNIT_MONSTER)
        {
            if (unit->dwMode && unit->dwMode != 0x0C)
                return ViewingTestMonster(unit) != 0;
        }
    }
    return FALSE;
}

BOOL ViewingTestMonster(UnitAny *mon)
{
    DWORD flag = D2CLIENT_GetMonsterTxt(mon->dwTxtFileNo)->flag1;

    return (flag & 0x1000000) && !(flag & 0x200);
}

void CheckD2WinEditBox()
{
    if (pD2WinEditBox)
    {
        if (D2CLIENT_GetUiVar(UIVAR_CHATINPUT))
        {
            if (*(DWORD*)p_D2CLIENT_szLastChatMessage != 0xAD5AFFFF)
            {
                D2WIN_DestroyEditBox(pD2WinEditBox);
                pD2WinEditBox = NULL;
                *p_D2WIN_pFocusedControl = NULL;
            }

            D2WIN_SetTextSize(1);
        }
    }
}

BOOL __cdecl InputLinePatch(BYTE keycode)
{
    if (bInputLinePatch && keycode != VK_ESCAPE)
    {
        if (keycode != VK_RETURN) 
            return TRUE;

        if (pD2WinEditBox)
            wcscpy(p_D2CLIENT_szLastChatMessage, D2WIN_GetEditBoxText(pD2WinEditBox));
    }
    return FALSE;
}

void __declspec(naked) InputLinePatch_ASM()
{
    __asm
    {
        mov ebx, eax
        push [edi+8]
        call InputLinePatch
        test eax, eax
        pop eax
        jz quitcode
        add dword ptr [esp], 0x427 // add to the point where function returns
    quitcode:
        ret
    }
}

BOOL __stdcall EditBoxCallBack(Control* hwnd, DWORD arg2, DWORD arg3)
{
    return TRUE;
}

BOOL __cdecl InitD2EditBox()
{
    if (!bInputLinePatch)
        return FALSE;

    if (!pD2WinEditBox)
    {
        static DWORD dws[] = { 0x0D, 0 };
        pD2WinEditBox = D2WIN_CreateEditBox(0x83,
            D2GetScreenSizeY()-58, D2GetScreenSizeX()-266,
            0x2D,
            0, 0, 0, 0, 0,
            sizeof(dws), &dws
            );
        *p_D2WIN_pFocusedControl = pD2WinEditBox;
        if (pD2WinEditBox)
        {
            D2WIN_SetEditBoxProc(pD2WinEditBox, &EditBoxCallBack);
            D2WIN_SetControlText(pD2WinEditBox, p_D2CLIENT_szLastChatMessage);
        }
        *(DWORD*)p_D2CLIENT_szLastChatMessage = 0x0AD5AFFFF;
    }
    if (pD2WinEditBox)
        (pD2WinEditBox->func)(pD2WinEditBox);

    return TRUE;
}

void __declspec(naked) InputLinePatch2_ASM()
{
    __asm
    {
        call InitD2EditBox
        test eax, eax
        jz quitcode
        add dword ptr [esp], 0x154
    quitcode:
        mov ecx, p_D2CLIENT_szLastChatMessage
        ret
    }
}

BYTE fLogInGameMessage = 0;
void __declspec(naked) MessageLogPatch1_ASM()
{
    __asm
    {
        cmp [fLogInGameMessage], 0
        je oldcode
        mov ecx, esi
        call D2LogMessage
        mov ecx, 0x0D
    oldcode:        
        jmp D2WIN_SetTextSize
    }
}

void __declspec(naked) MessageLogPatch2_ASM()
{
    __asm
    {
        cmp [fLogInGameMessage], 0
        je oldcode
        mov ecx, ebp
        call D2LogMessage
        mov ecx, 0x0D
    oldcode:        
        jmp D2WIN_SetTextSize
    }
}