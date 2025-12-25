<h1>C-Basic+</h1>

<div style="display: flex; align-items: center; gap: 15px;">
  <img src="./Doc/LogoCBasic.png" width="100" alt="C-Basic+ Logo">
  <h3>C-Basic+ is a programming language developed by <strong>FuSoft</strong>.</h3>
</div>

<p>
C-Basic+ is written in <strong>C++ using an older standard</strong> to ensure cross-platform compatibility. It is highly optimized for speed and can even run on <strong>Windows 98</strong>.
</p>

<p>
The main goal of C-Basic+ is <strong>software development</strong>. It is actively maintained and will continue to receive updates, including new syntax and libraries. Currently, it provides a set of simple syntax elements sufficient for writing programs.
</p>

<p>
<b>In the future, with its libraries, C-Basic+ aims to enable developers to create an entire operating system.</b>
</p>

<p>
The language is currently at <strong>version 1.0.0</strong> and is licensed under the <u>GNU License</u>.
</p>

<h4>Features:</h4>
<ul>
  <li>💻 <strong>Cross-platform:</strong> Runs on Mac OS, Windows, Linux, and even Windows 98.</li>
  <li>🛠️ <strong>High performance:</strong> Optimized for older systems with weak CPUs and 32-bit architecture.</li>
  <li>📃 <strong>Old standard C++:</strong> Compiled using <em>GCC version 4.6.1 (TDM-1)</em>.</li>
  <li>⌨️ <strong>Interpreted language:</strong> Whitespace is not strictly enforced, and error messages are clear and informative (future versions will improve this further).</li>
  <li>🚀 <strong>Expandable:</strong> More features and libraries will be added in future releases.</li>
</ul>
<p><b>⚠️ Currently, there is no officially defined standard file format for C-Basic+.</b></p>
<p>if the Code is not work in Linux, Use dos2unix for Fix</p>
<h2>Dos2unix</h2>
<pre><code>
  sudo apt install dos2unix
</code></pre>
<pre><code>
  dos2unix app.cbp
</code></pre>
<hr>








<h2>Simple Program</h2>
<pre><code>
//This is Simple Program
print("Hello World\nThis Program Running in %os%\n");
sleep(1.0);
print(":) " & "happy\n");
system("pause");
print("\a");
print("Pess any key to Exit.");
system("pause >nul");
//You Can't Write this:
exit();
</code></pre>



<h2>Command to Run Code</h2>
<pre><code>
cbp -file app.cbp
</code></pre>
