# AmazingHackCH1
AmazingHackCH1


Solution is implemented as two servers Bloader and Bquery. Bloader loads CSV files and stores in separate .data files based on Hashing logic.
Individual .data files are noted in .index files for reference. Also, the individual itemno are identified and stored in seprate file for subscriber to parse and notify

Bquery, hits the index files and identify the .data file for individual itemno and retrieves the value
