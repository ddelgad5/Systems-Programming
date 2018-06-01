import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

/**
 * Chef Gordon RAMsay's Decoder for Secret Recipe Files
 * ----------------------------------------------------
 * This program must be in the same directory as the secret recipe file, called recipe.txt
 *
 * To decode the recipe, run the following in the terminal (no $):
 * $ javac RecipeDecoder.java
 * $ java RecipeDecoder
 *
 * The results will be in the file decoded_recipe.txt
 * To read the results, run the following in the terminal (no $):
 * $ cat decoded_recipe.txt
 *
 */
public class RecipeDecoder {

	private static final String ALPHABET = "0123456789ABDEFGHIJKLMNOPQRSTUVWXYZ";

	public static void main(String args[]) {
		try {
			File file = new File("recipe.txt");
			String[] keys = {"", "", ""};
			Scanner scan = new Scanner(System.in);
			System.out.println("Welcome back, Chef RAMsay. Please answer your security questions.");
			System.out.println("In which year did you graduate from the culinary academy?");
			System.out.print("> ");
			keys[0] = scan.nextLine().toUpperCase();
			System.out.println("What sauce pairs best with raspberry?");
			System.out.print("> ");
			keys[1] = scan.nextLine().toUpperCase();
			System.out.println("What was the first dish you ever made?");
			System.out.print("> ");
			keys[2] = scan.nextLine().toUpperCase();
			File output = new File("decoded_recipe.txt");
			decodeFile(file, output, keys);
			System.out.println("Decoding complete.");
		} catch (FileNotFoundException fe) {
			fe.printStackTrace();
		}
		
	}

	/**
	 * Uses the security question responses to decode a secret recipe
	 * @param file: file to decode
	 * @param output: file to write decoded recipe to
	 * @param keys: security question responses for decoding process
	 */
	public static void decodeFile(File file, File output, String[] keys) throws FileNotFoundException {
		PrintWriter pw = new PrintWriter(output);
		Scanner scan = new Scanner(file);
		String letters = scan.nextLine();
		int count = 0;
		while (scan.hasNextLine()) {
			String line = scan.nextLine();
			int keyIndex = count % keys.length;
			String lineKey = keys[keyIndex];
			if (lineKey.length() > 0) {
				char keyLetter = lineKey.charAt(count % lineKey.length());
				int alphaIndex = RecipeDecoder.ALPHABET.indexOf(keyLetter);
				String codedLine = "";
				for (int i = 0; i < line.length(); i++) {
					char c = line.charAt(i);
					String letter = c + "";
					c = letter.toLowerCase().charAt(0);
					int codeIndex = (letters.indexOf(c) - alphaIndex) % letters.length();
					if (codeIndex < 0) {
						codeIndex = letters.length() + codeIndex;
					}
					String addition = "" + letters.charAt(codeIndex);
					codedLine += addition;
				}
				pw.println(codedLine);
			} else {
				pw.println(line);
			}
			count++;
		}
		scan.close();
		pw.close();
	}

}