LC_DIR := lc

.PHONY: lc lc-ds

lc:
	@num=$(word 2, $(MAKECMDGOALS)); \
	mkdir -p $(LC_DIR); \
	> $(LC_DIR)/$$num.cpp; \
	echo "Created: $(LC_DIR)/$$num.cpp"

lc-ds:
	@num=$(word 2, $(MAKECMDGOALS)); \
	mkdir -p $(LC_DIR); \
	echo "#include \"common_ds.h\"" > $(LC_DIR)/$$num.cpp; \
	echo "Created with ds: $(LC_DIR)/$$num.cpp"

%:
	@:
