# Raylib Game Template
The Raylib Game Template was created as an easy start to using Raylib. It is configured to be able to easily setup a C++ Visual Studio 2022 project with Raylib already linked and setup.

***

### Getting started
This requires Visual Studio 2022 to be installed. If you do not have that installed already, you can download it here [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/)

<ins>**1. Setting up the repository:**</ins>

Start by clicking on the "Use this template" button and then click "Create a new repository".

![GitTemplateUse](/docs/images/git_template_use.png?raw=true)

You will be then greeted to this screen here below. In the box below repository name, just put the name of your game in.
<p>(Note do not put raylib as the name, the project setup later will not work)</p>

![GitCreateNewRepository](/docs/images/git_create_new_repository.png?raw=true)

Afterwards you will be then greeted to the new repository.


<ins>**2. Cloning your new repository:**</ins>

Next you want to clone your new repository.
<p>First you need to get the URL to clone from. To do this just click the code button then click on the button next to the URL that ends with ".git"</p>

![GitCloneRepository](/docs/images/git_clone_repository.png?raw=true)

Then in the Windows file explorer go to the directory where you want to clone your new repository to and open the command prompt window in that directory.
<br />
An easy way to do this is to click on the address box next to search and type `cmd`

![FileExplorerCmd](/docs/images/file_explorer_cmd.png?raw=true)

Once the command prompt window is open, simply type `git clone` and then paste the git URL you had copied earlier. For example with my repository it is `git clone https://github.com/marc-crAIE/GameExample.git`.

![GitCloneCommand](/docs/images/git_clone_command.png?raw=true)

You should have a new folder with your repository name created and the files inside should look like this.

![GitInitialFolder](/docs/images/git_initial_folder_setup.png)

<ins>**3. Setting up the project:**</ins>

This part is easy and fairly straight forward.
<br />
Run the [Setup.bat](/Setup.bat) file and you should see a windows command prompt screen open. As long as everything was done correctly you should see an output window similar to this with `GameExample` be replaced with the name of your project.

![ProjectSetupPremake5Output](/docs/images/project_setup_premake5_output.png?raw=true)

Once that has been completed you should now see a Visual Studio Solution file with the name of your project. All you have to do is open that and Visual Studio 2022 should open with everything ready to go!

![ProjectPostSetup](/docs/images/project_post_setup.png?raw=true)

<ins>**4. Testing the project:**</ins>

Just to make sure it is working correctly, after opening the Visual Studio solution. Press F5 on your keyboard or click the green play button at the top that usually says "Local Windows Debugger". If all goes well you should have the project build successfully and be greeted to the below Raylib window.

![ExampleWindow](/docs/images/example_window.png?raw=true)
