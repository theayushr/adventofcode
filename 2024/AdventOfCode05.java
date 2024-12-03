import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class AdventOfCode05 {

  private static final String input = "input.txt";
  private static final String sample = "sample.txt";
  private final Pattern regex = Pattern.compile("mul\\((?<first>[\\d]{1,3}),(?<second>[\\d]{1,3})\\)");
  long result = 0;

  public static void main(String[] args) {
    new AdventOfCode05().adventOfCode();
  }

  void adventOfCode() {
    try {
      File inputFile = new File(input);
      BufferedReader reader = new BufferedReader(new FileReader(inputFile));
      reader.lines().forEach(line -> {
        Matcher matcher = regex.matcher(line);
        while (matcher.find()) {
          int first = Integer.parseInt(matcher.group("first"));
          int second = Integer.parseInt(matcher.group("second"));
          result += (long) first * second;
        }
      });
      System.out.println(result);
    } catch (FileNotFoundException fe) {
      System.out.println(fe.getMessage());
    }
  }
}
