# MassZombies

Being developed using Unreal Engine 5.2 to learn [MASS](https://docs.unrealengine.com/5.2/en-US/overview-of-mass-entity-in-unreal-engine/)

5000(at startup) Zombies moving towards player car while avoiding each other and getting run over.

Zombies : 
- They have a single animation made with AnimToTexture plugin.
- Their UV Channel 0 is overrided by AnimToTexture plugin(mesh problem) :( so they look a bit off when you close in on them.
- All of the meshes are Static Mesh Instance.
- They avoid eachother while moving towards player.

Zombie Killing :
- (Not Used) Killing Them With ***Collision*** :
  - To do this i had to use actors and that cut down fps by half.
  - Also you have to tinker with LOD too much to get even a okay result.
- Killing Them With ***UKismetMathLibrary::IsPointInBox***
    - ***UKillZombiesInAreaProcessor*** checks every frame for overlaps. 
    - Allowed me to use Static Mesh Instance in all Zombies.
    - Its a hardcoded box.

Performance :
- Fps is 25-30 in startup and goes up when killing zombies.
- I have a good gaming pc(3060ti 5600x) so 30fps is not fantastic.
- It could be way better probably. I will try to improve over time

# Showcase

Click image to go to youtube.
[![Video](https://img.youtube.com/vi/O0V02DX2SNE/maxresdefault.jpg)](https://www.youtube.com/watch?v=O0V02DX2SNE)
