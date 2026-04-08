if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    all_dic = {"Strategist", "Speed Runner", "Survivor",
               "Master Explorer", "Treasure Hunter", "First Steps",
               "Collector Supreme", "Untouchable", "Sharp Mind",
               "Crafting Genius", "World Savior",
               "Hidden Path Finder", "Untouchable",
               "Boss Slayer"}
    set1 = {"Crafting Genius", "World Savior", "Master Explorer",
            "Collector Supreme", "Untouchable", "Boss Slayer"}
    set2 = {"Crafting Genius", "Strategist", "World Savior",
            "Master Explorer", "Unstoppable",
            "Collector Supreme", "Untouchable"}
    set3 = {"Strategist", "Speed Runner", "Survivor",
            "Master Explorer", "Treasure Hunter", "First Steps",
            "Collector Supreme", "Untouchable", "Sharp Mind"}
    set4 = {"Strategist", "Speed Runner", "Unstoppable",
            "Untouchable", "Boss Slayer"}
    print(f"Player alice:  {set1}")
    print(f"Player bob:  {set2}")
    print(f"Player charlie:  {set3}")
    print(f"Player Dylan:  {set4}\n")
    print(f"All distinct achievements:  {set1 | set2 | set3 | set4}")
    print(f"\nCommon achievements:  {set1 & set2 & set3 & set4}\n")
    print(f"Only Alice has:  {set1 - (set2 | set3 | set4)}")
    print(f"Only Bob has:  {set2 - (set1 | set3 | set4)}")
    print(f"Only Charlie has:  {set3 - (set2 | set1 | set4)}")
    print(f"Only Dylan has:  {set4 - (set2 | set3 | set1)}\n")
    print(f"Alice is missing:  {all_dic - set1}")
    print(f"Bob is missing:  {all_dic - set2}")
    print(f"Charlie is missing:  {all_dic - set3}")
    print(f"Dylan is missing:  {all_dic - set4}")
