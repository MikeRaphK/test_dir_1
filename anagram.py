def is_anagram(s1, s2):
    s1_clean = ''.join(s1.lower().split())
    s2_clean = ''.join(s2.lower().split())
    return sorted(s1_clean) == sorted(s2_clean)
