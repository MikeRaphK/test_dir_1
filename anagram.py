def is_anagram(s1, s2):
    s1_cleaned = ''.join(s1.lower().split())
    s2_cleaned = ''.join(s2.lower().split())
    return sorted(s1_cleaned) == sorted(s2_cleaned)
