def is_anagram(s1, s2):
    # Remove spaces and convert to lowercase before comparing sorted characters
    return sorted(s1.replace(" ", "").lower()) == sorted(s2.replace(" ", "").lower())