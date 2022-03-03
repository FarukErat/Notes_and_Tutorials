#ifndef REPLACE_H
#define REPLACE_H

#include <string.h> // strlen, strcpy

/**
 * @brief replace all occurences of a substring in a string by reference
 *
 * @param text the string to be modified
 * @param rep the substring to be replaced
 * @param with the substring to replace the rep
 */
void replace(char text[], char rep[], char with[])
{
	int count = 0;				// to compare the length of rep and with
	int textLen = strlen(text); // length of text
	int repLen = strlen(rep);	// length of the text to be replaced
	int withLen = strlen(with); // length of the text to replace with
	char copyText[textLen];		// copy of text to save a copy for later use
	strcpy(copyText, text);
	for (int i = 0; i < textLen; i++)
	{
		// check if the new text occur in the old text
		for (int j = 0; j < repLen; j++)
		{
			if (text[i + j] == rep[j])
			{
				count++;
			}
		}
		// if count matches the old text length then replace the old text with the new text
		if (count == repLen)
		{
			// alter the occurence of the old text with the new text
			for (int j = 0; j < withLen; j++)
			{
				text[i + j] = with[j];
			}
			// if the lengths do not match then shift the text accordingly
			if (withLen != repLen)
			{
				int diff = withLen - repLen;
				// increment the text length by the difference
				textLen += diff;
				// the shift will not be done before the occurence of the old text
				// that is why (i + newLen) is subtracted from the text length
				// to shift the string terminator, 1 is added
				for (int j = 0; j < textLen - (i + withLen) + 1; j++)
				{
					// (i + newLen) is where the shift will start and j is to iterate through the text
					// copyText is the string that remains unchanged from the previous operation
					// the uncganged part starts at i + oldLen in the copyText
					text[(i + withLen) + j] = copyText[(i + repLen) + j];
				}
			}
			strcpy(copyText, text);
			// iterate i to skip the replaced text
			// -1 to cancel the increment in the for loop
			i += withLen - 1;
		}
		// reset count
		count = 0;
	}
	return;
}

#endif // REPLACE_H
