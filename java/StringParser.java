package java;

import java.util.Scanner;

public class StringParser {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(parseRoom(scanner.nextLine()));
        scanner.close();
    }

    private static String parseRoom(String toParse) {
        StringBuilder builder = new StringBuilder();
        int finalIndexOfRoom = -1;
        // int finalIndexOfEd = -1;

        builder.append("(");

        if (toParse.contains("Ed"))
            finalIndexOfRoom = toParse.indexOf("Ed");
            
        else if (toParse.contains("Lab"))
            finalIndexOfRoom = toParse.indexOf("Lab");

        if (finalIndexOfRoom == -1)
            return "'None'";

        else {
            builder.append("'");
            for (int i = 1; i < finalIndexOfRoom; i++) {
                if (i == 1) builder.append(toParse.charAt(0)); else builder.append(toParse.charAt(i - 1));
            }
            builder.append("'"); builder.append(", ");
        }

        builder.append(")");
        return builder.toString();
    }
}