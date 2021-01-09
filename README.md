# CoronaSafe Engineering Fellowship Test Problem

Here's how it will work:-

[![Todo-CLI](https://res.cloudinary.com/sv-co/image/upload/v1607935139/fullstack-CEF/Todo-CLI/play-video-demo_fp50wp.png)](https://vimeo.com/490621534)

## Getting started

1. Install CPP: You should have build support for cpp on your system.

2. You are expected to write the code in `todo.cpp` file.

3. You should be able to build the app by running `make app`.

4. Once you are done with the changes you should be able to execute the todo app by running the following command from the terminal.

   **On Windows:**

   ```
   .\todo.bat
   ```

   **On \*nix:**

   ```
   ./todo.sh
   ```

## Run Automated Tests

### 1. Install Node.js

You need to have npm installed in your computer for this problem. It comes with Node.js and you can get it by installing Node from https://nodejs.org/en/

### 2. Install dependencies

Run `npm install` to install all dependencies.

### 3. Create Create symbolic link to the executable file

#### On Windows

To create a symbolic link on Windows, you'll need to run either the Windows Command Prompt, or Windows Powershell **with administrator privileges**. To do so, right-click on the icon for Command Prompt, or Powershell, and choose the _"Run as Administrator"_ option.

**Command Prompt:**

```
> mklink todo todo.bat
```

**Powershell:**

```
> cmd /c mklink todo todo.bat
```

#### On \*nix:

Run the following command in your shell:

```
$ ln -s todo.sh todo
```

### 4. Try running tests.

Now run `npm test` and you will see all the tests failing. As you fill in each functionality, you can re-run the tests to see them passing one by one.

## A Note about `/` for Windows Users

In the following sections, you'll see many commands prefixed with `./`, or paths containing the `/` (forward-slash) character.

If you're using the Windows _Command Prompt_, then you'll need to replace `/` with `\` (back-slash) for these commands and paths to work as expected.

On Windows _Powershell_, these substitutions are not required.

## Known Issues

A few notes to help you avoid any hiccups while implementing the programming challenge:

1. If you are on Windows, you might have difficulty getting the tests to pass because of newline UTF encoding issues. If you get stuck, please [refer to the thread here](https://github.com/nseadlc-2020/package-todo-cli-task/issues/12).

2. The tests can fail between 12am and 5.30am (early morning IST). This is because the test parses the date from your system time in UTC format, while in certain programming languages the date and time functions use the local timezone (IST). Accounting for this in the tests will make it more complex and need extra dependencies, so we have kept it intentionally simple. So if you run into this specific problem, you can submit your code as is with the transient date mismatch, or you can change your code to use UTC. Either options are fine.

3. In Windows machines, the `make` command might not exist and can prevent you from running the tests. This can be fixed [by using WSL, or installing MinGW, among other options](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows).


## Usage

### 1. Help

Executing the command without any arguments, or with a single argument `help` prints the CLI usage.

```
$ ./todo help
```

### 2. List all pending todos

Use the `ls` command to see all the todos that are not yet complete. The most recently added todo should be displayed first.

```
$ ./todo ls
```

### 3. Add a new todo

Use the `add` command. The text of the todo item should be enclosed within double quotes (otherwise only the first word is considered as the todo text, and the remaining words are treated as different arguments).

```
$ ./todo add "the thing i need to do"
```

### 4. Delete a todo item

Use the `del` command to remove a todo item by its number.

```
$ ./todo del 3
```

Attempting to delete a non-existent todo item should display an error message.

```
$ ./todo del 5
```

### 5. Mark a todo item as completed

Use the `done` command to mark a todo item as completed by its number.

```
$ ./todo done 1
```

Attempting to mark a non-existed todo item as completed will display an error message.

```
$ ./todo done 5
```

### 6. Generate a report

Use the `report` command to see the latest tally of pending and completed todos.

```
$ ./todo report
```
