// 1948. Delete Duplicate Folders in System
class Solution
{
public:
    // Tree node to represent each folder
    struct TrieNode
    {
        unordered_map<string, TrieNode *> children;
        bool toDelete = false; // Flag to mark if this folder should be deleted
    };

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        TrieNode *root = new TrieNode();

        // Step 1: Build the file system tree
        for (auto &path : paths)
        {
            TrieNode *curr = root;
            for (string &folder : path)
            {
                if (curr->children.find(folder) == curr->children.end())
                {
                    curr->children[folder] = new TrieNode();
                }
                curr = curr->children[folder];
            }
        }

        // Step 2: Generate signatures and find duplicates
        unordered_map<string, int> signatureCount;
        generateSignatures(root, signatureCount);

        // Step 3: Mark folders for deletion
        markForDeletion(root, signatureCount);

        // Step 4: Collect remaining paths
        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);

        return result;
    }

private:
    // Generate signature for each folder using post-order traversal
    string generateSignatures(TrieNode *node, unordered_map<string, int> &signatureCount)
    {
        if (!node)
            return "";

        vector<string> childSignatures;

        // Process all children first (post-order)
        for (auto &[folderName, childNode] : node->children)
        {
            string childSig = generateSignatures(childNode, signatureCount);
            // Include folder name with its signature
            childSignatures.push_back(folderName + "(" + childSig + ")");
        }

        // Sort to ensure consistent signature regardless of insertion order
        sort(childSignatures.begin(), childSignatures.end());

        // Create signature for current node
        string signature = "";
        for (string &childSig : childSignatures)
        {
            signature += childSig;
        }

        // Only count non-empty signatures (ignore leaf folders and root)
        if (!signature.empty())
        {
            signatureCount[signature]++;
        }

        return signature;
    }

    // Mark folders for deletion if they have duplicate signatures
    void markForDeletion(TrieNode *node, unordered_map<string, int> &signatureCount)
    {
        if (!node)
            return;

        // Generate signature again for this node
        vector<string> childSignatures;
        for (auto &[folderName, childNode] : node->children)
        {
            string childSig = getNodeSignature(childNode);
            childSignatures.push_back(folderName + "(" + childSig + ")");
        }
        sort(childSignatures.begin(), childSignatures.end());

        string signature = "";
        for (string &childSig : childSignatures)
        {
            signature += childSig;
        }

        // Mark for deletion if signature appears more than once
        if (!signature.empty() && signatureCount[signature] > 1)
        {
            node->toDelete = true;
            return; // Don't process children of deleted folders
        }

        // Process children
        for (auto &[folderName, childNode] : node->children)
        {
            markForDeletion(childNode, signatureCount);
        }
    }

    // Helper function to get signature of a node
    string getNodeSignature(TrieNode *node)
    {
        if (!node)
            return "";

        vector<string> childSignatures;
        for (auto &[folderName, childNode] : node->children)
        {
            string childSig = getNodeSignature(childNode);
            childSignatures.push_back(folderName + "(" + childSig + ")");
        }
        sort(childSignatures.begin(), childSignatures.end());

        string signature = "";
        for (string &childSig : childSignatures)
        {
            signature += childSig;
        }
        return signature;
    }

    // Collect all paths that are not marked for deletion
    void collectPaths(TrieNode *node, vector<string> &currentPath, vector<vector<string>> &result)
    {
        if (!node)
            return;

        for (auto &[folderName, childNode] : node->children)
        {
            // Skip deleted folders
            if (childNode->toDelete)
                continue;

            currentPath.push_back(folderName);
            result.push_back(currentPath);

            // Continue with children
            collectPaths(childNode, currentPath, result);

            currentPath.pop_back(); // Backtrack
        }
    }
};