#include "HuffmanTree.h"

int main()
{
	HuffmanTree tree;
	std::string text = "text.txt";
	std::string encodeText = "encodeText.txt";
	tree.build(text);
	tree.encode(text, encodeText);
}