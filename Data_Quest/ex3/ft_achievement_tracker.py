if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    set1 = {"first_kill", "level_10", "treasure_hunter", "speed_demon"}
    set2 = {"first_kill", "level_10", "boss_slayer", "collector"}
    set3 = {"level_10", "treasure_hunter", "boss_slayer",
            "speed_demon", "perfectionist"}
    print(f"Player alice achievements:  {set1}")
    print(f"Player bob achievements:  {set2}")
    print(f"Player charlie achievements:  {set3}")
    print("\n=== Achievement Analytics ===")
    print(f"All unique achievements:  {set1 | set2 | set3}")
    print(f"Total unique achievements:  {len(set1 | set2 | set3)}\n")
    print(f"Common to all players:  {set1 & set2 & set3}")
    rare = set1 - (set2 | set3) | set2 - (set1 | set3) | set3 - (set1 | set2)
    print(f"Rare achievements (1 player):  {rare}\n")
    print(f"Alice vs Bob common:  {set1 & set2}")
    print(f"Alice unique:  {set1 - set2}")
    print(f"Bob unique:  {set2 - set1}")
