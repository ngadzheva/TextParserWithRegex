# TextParserWithRegex
<p> The purpose of this project is to develop an application that allows the user to search in text files using regular expressions. </p>
<p> The app should get the following arguments from the command line: </p>
<ol>
  <li> File name or directory to be processed </li>
  <li> Regular expression. </li>
</ol>
<p> If a file name is given to the app, it should display all file rows that match the regular expression. The output must be in the following format: </p>
<p> <b> &lt;filename&gt;: &lt;line number&gt;: &lt;text&gt; </b> </p>
 <br/>
  <p> <i> For example: </i> </p>
  <p> <i> <b> > RegExSearch.exe MyFile.txt "(a*)" </b> </i> </p>
  <p> <i> <b> MyFile.txt:5:aaaaaa </b> </i> </p>
  <p> <i> <b> MyFile.txt:15:aaa </b> </i> </p>
  <p> <i> <b> MyFile.txt:16:aaaaaaaaaa  </b> </i> </p>
  
  <br/>
  
 <p> When handling rows, the application <b> MUST BE </b> case-insensitive. </p>
 
 <br/>
 <p> To solve the task, the program needs to implement a suitable algorithm that, by a regular expression E, constructs an undetermined end machine A with the language ℒ (𝐸) = ℒ (𝐴). The machine should then be used to analyze each of the rows and those of them whose processing has brought it to the final state to be displayed on the screen. </p>
 <p> The regular expression that will be given to the decision may contain zero, one or more characters. For the sake of clarity, if an empty expression is given (ie, the user submits an empty string as a regular expression), we consider that it matches each line of the file. Valid symbols are those with codes from 33 to 126 of the ASCII table (so-called symbols that have a graphical representation). If an expression is entered at the input that contains characters other than valid characters, the program should output an error message. </p>
 
 <br/>
 <p> The semantics of special symbols and expressions are as follows: </p>
 <ol>
  <li> \s matches any whitespace. Such are spaces, tabs, new rows, etc; </li>
  <li> \d matches any number; </li>
  <li> \a coincides with any letter of the Latin alphabet - small or large; </li>
  <li> \e is interpreted as the empty word; </li>
  <li> \\ is interpreted as one slash; </li>
  <li> The dot symbol (.) Is a concatenation. Two others are involved in this expression - E 1 and E 2. It recognizes a text whose first part corresponds to E 1 and its second to E 2. </li>
  <li> The vertical line symbol (|) is a union. Two others are involved in this expression - E 1 and E 2. It recognizes text that corresponds to E 1 or E 2. </li>
  <li> The star symbol (*) denotes iteration. In such expression, one participates - E. It recognizes either the empty string (zero occurrence of E) or one or more occurrences of E, i. (E, E), ((E, E), E) ((E, E), E), E) etc . </li>
  </ol>
