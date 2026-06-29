import zipfile
import os

def create_vsix():
    vsix_name = "nova-language-1.0.0.vsix"
    files_to_pack = ["package.json", "language-configuration.json", "syntaxes/nova.tmLanguage.json"]
    
    with zipfile.ZipFile(vsix_name, 'w') as vsix:
        for file in files_to_pack:
            if os.path.exists(file):
                vsix.write(file)
                print(f"[Packer] Added {file}")
            else:
                print(f"[Error] Missing {file}")
                
    print(f"✅ Successfully created {vsix_name}")

if __name__ == "__main__":
    create_vsix()
