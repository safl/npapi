default: clean emit

emit:
	yace nvme.yaml --emit npapi

clean:
	rm -r output || true
