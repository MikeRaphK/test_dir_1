def is_anagram(s1, s2):
    # Normalize the strings by removing spaces and converting to lower case
    s1 = s1.replace(' ', '').lower()
    s2 = s2.replace(' ', '').lower()
    # Check if sorted characters of both strings are equal
    return sorted(s1) == sorted(s2)