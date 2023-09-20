
#  Python_organize_assets_Unreal
#  Tool-> Python



import unreal

# Define the source directory where your assets are located
source_directory = "C:/MyGameAssets"

# Get the content browser
content_browser = unreal.EditorUtilityLibrary.get_content_browser()

# Define a dictionary mapping asset classes to target directories
class_to_directory = {
    "StaticMesh": "/Game/Assets/StaticMeshes",
    "Texture2D": "/Game/Assets/Textures",
    "Material": "/Game/Assets/Materials",
    # Add more asset classes and target directories as needed
}

# Iterate through the source directory to organize assets
for asset_class, target_directory in class_to_directory.items():
    # Create the target directory if it doesn't exist
    if not unreal.EditorAssetLibrary.does_directory_exist(target_directory):
        unreal.EditorAssetLibrary.make_directory(target_directory)

    # Find assets of the specified class in the source directory
    asset_paths = unreal.EditorAssetLibrary.list_assets(source_directory, recursive=True, asset_class=asset_class)

    # Move each asset to the corresponding target directory
    for asset_path in asset_paths:
        asset_name = unreal.EditorAssetLibrary.get_asset_name(asset_path)
        new_asset_path = target_directory + "/" + asset_name
        unreal.EditorAssetLibrary.rename_asset(asset_path, new_asset_path)

# Refresh the content browser to reflect changes
content_browser.asset_path = source_directory
