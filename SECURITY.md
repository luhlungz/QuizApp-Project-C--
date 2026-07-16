# Security notice

The original desktop project stored usernames and passwords in plain text inside `Users.txt`. Real credentials must not be committed or stored this way.

The committed account file has been replaced with a non-sensitive example. A production version should use a proper identity provider or a database that stores salted password hashes.

Accounts created in the static browser demonstration remain on the visitor's device and use a SHA-256 digest. This is suitable only for a portfolio demonstration, not production authentication.
