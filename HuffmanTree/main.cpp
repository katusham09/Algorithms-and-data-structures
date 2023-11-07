#include "HuffmanTree.h"

int main()
{
	HuffmanTree tree;
	std::string text = "text.txt";
	std::string encodedText = "encodeText.txt";
	std::string decodedText = "decodeText.txt";

	tree.build(text);
	tree.encode(text, encodedText);
	tree.decode(encodedText, decodedText);
}