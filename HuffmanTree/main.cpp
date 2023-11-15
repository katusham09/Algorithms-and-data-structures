#include "HuffmanTree.h"

int main()
{
	HuffmanTree tree;
	std::string text = "text.txt";
	std::string encodedText = "encodeText.txt";
	std::string decodedText = "decodeText.txt";

	tree.build(text);
	std::cout << "compression = " << tree.encode(text, encodedText) << std::endl;
	tree.decode(encodedText, decodedText);
}